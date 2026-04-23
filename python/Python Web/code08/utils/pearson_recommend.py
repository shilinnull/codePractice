from utils.con_to_db import query_data
from math import sqrt

# 缓存所有推荐数据，避免重复查询
_all_recommend_data = None


def _get_all_recommend_data():
    """一次性获取所有推荐数据，避免多次数据库查询"""
    global _all_recommend_data
    if _all_recommend_data is None:
        sql = 'select user_id, house_id, score from house_recommend'
        result = query_data(sql)
        # 转换为 {user_id: {house_id: score, ...}, ...}
        _all_recommend_data = {}
        for info in result:
            user_id, house_id, score = info
            if user_id not in _all_recommend_data:
                _all_recommend_data[user_id] = {}
            _all_recommend_data[user_id][house_id] = score
    return _all_recommend_data


def get_total_u_id():
    """获取推荐表中所有的用户ID"""
    data = _get_all_recommend_data()
    return list(data.keys())


def get_user_info(user_id):
    """获取指定用户的浏览记录"""
    data = _get_all_recommend_data()
    if user_id in data:
        return {user_id: data[user_id]}
    return {}


def pearson_sim(user1, sim_user):
    """计算两个用户的相似度"""
    all_data = _get_all_recommend_data()

    if user1 not in all_data or sim_user not in all_data:
        return 0

    user1_data = all_data[user1]
    user2_data = all_data[sim_user]

    # 找到共同的浏览房源
    common = []
    for key in user1_data.keys():
        if key in user2_data.keys():
            common.append(key)

    if len(common) == 0:
        return 0

    n = len(common)
    user1_sum = sum([user1_data[hid] for hid in common])
    user2_sum = sum([user2_data[hid] for hid in common])
    pow_sum1 = sum([pow(user1_data[hid], 2) for hid in common])
    pow_sum2 = sum([pow(user2_data[hid], 2) for hid in common])
    PSum = sum([float(user1_data[hid] * float(user2_data[hid])) for hid in common])

    molecule = PSum - (user1_sum * user2_sum / n)
    denominator = sqrt(pow_sum1 - (user1_sum ** 2) / n) * (pow_sum2 - (user2_sum ** 2) / n)

    if denominator == 0:
        return 0
    return molecule / denominator


def top10_similar(UserID):
    """获取相似度在前十名的用户"""
    total_u_id = get_total_u_id()
    res = []
    for u_id in total_u_id:
        if int(UserID) != u_id:
            similar = pearson_sim(int(UserID), int(u_id))
            if similar > 0:
                res.append((u_id, similar))
    res.sort(key=lambda val: val[1], reverse=True)
    return res[:10]


def recommend(user):
    """获取推荐的房源"""
    if len(top10_similar(user)) == 0:
        return None

    top_sim_user = top10_similar(user)[0][0]
    all_data = _get_all_recommend_data()

    items = all_data.get(top_sim_user, {})
    user_data = all_data.get(user, {})

    recommendata = []
    for item in items.keys():
        if item not in user_data.keys():
            recommendata.append((item, items[item]))

    recommendata.sort(key=lambda val: val[1], reverse=True)
    if len(recommendata) > 6:
        return recommendata[:6]
    else:
        return recommendata


def clear_cache():
    """清除缓存，以便在数据更新后重新加载"""
    global _all_recommend_data
    _all_recommend_data = None