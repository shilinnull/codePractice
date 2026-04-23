from flask import Blueprint, request, render_template, url_for, redirect
from models import House
import math

# 创建蓝图对象
list_page = Blueprint('list_page', __name__)

"""
实现搜索列表页的功能
1. 定义一个路由为 /query的视图函数
2. 使用request 获取到请求字段 具体的查询信息
3. 使用sqlalchemy 在字段中 查询具体的信息 获取满足这个条件的房源
4. 使用publish_time字段，进行降序排序
5. 使用render_template进行渲染
"""


@list_page.route('/query')  # http://127.0.0.1:5000/query?addr=朝阳-三里屯-三里屯SOHO
def search_txt_info():
    # 获取地区字段的查询
    if request.args.get('addr'):
        addr = request.args.get('addr')
        result = House.query.filter(House.address == addr).order_by(House.publish_time.desc()).all()
        return render_template('search_list.html', house_list=result)

    # 获取户型字段的查询
    if request.args.get('rooms'):
        rooms_info = request.args.get('rooms')
        result = House.query.filter(House.rooms == rooms_info).order_by(House.publish_time.desc()).all()
        return render_template('search_list.html', house_list=result)
    return redirect(url_for('index_page.index'))


# 最新房源列表页展示的功能
"""
1. 去定义一个视图函数 /list/pattern/<int:page>  method=get
2. 获取全部的房源数据，再根据房源的发布时间 publish_time 字段进行降序排序
3. 实现分页功能 借助分页插件 和 paginate函数来完成
4. 使用render_template进行渲染
"""


@list_page.route('/list/pattern/<int:page>')
def return_new_list(page):
    # 获取房源总数量
    house_num = House.query.count()
    # 计算总的页码数，向上取整
    total_num = math.ceil(house_num / 10)
    # 处理页码超出范围的情况
    if page < 1:
        page = 1
    elif page > total_num:
        page = total_num if total_num > 0 else 1
    result = House.query.order_by(
        House.publish_time.desc()).paginate(page=page, per_page=10)
    return render_template('list.html', house_list=result.items, page_num=result.page, total_num=total_num)


# 最热房源列表页展示的功能
@list_page.route('/list/hot_house/<int:page>')
def return_hot_list(page):
    # 获取房源总数量
    house_num = House.query.count()
    # 计算总的页码数，向上取整
    total_num = math.ceil(house_num / 10)
    # 处理页码超出范围的情况
    if page < 1:
        page = 1
    elif page > total_num:
        page = total_num if total_num > 0 else 1
    result = House.query.order_by(
        House.page_views.desc()).paginate(page=page, per_page=10)
    return render_template('list.html', house_list=result.items, page_num=result.page, total_num=total_num)


def deal_title_over(word):
    if len(word) > 15:
        return word[:15] + '...'  # 当房源标题长度大于15时，用省略号替换
    else:
        return word


def deal_direction(word):
    if len(word) == 0 or word is None:  # 房源朝向、交通条件为空时显示暂无信息
        return '暂无信息！'
    else:
        return word


# 根据house的id循环显示不同的图片
def get_house_image(house_id):
    image_list = ['/static/img/house-bg1.jpg', '/static/img/house-bg2.jpeg', '/static/img/house-gb.jpg']
    return image_list[house_id % 3]


list_page.add_app_template_filter(deal_title_over, 'dealover')
list_page.add_app_template_filter(deal_direction, 'dealdirection')
list_page.add_app_template_filter(get_house_image, 'houseimage')
