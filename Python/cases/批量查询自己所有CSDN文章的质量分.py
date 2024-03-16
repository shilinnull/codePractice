import json
import pandas as pd
from openpyxl import Workbook, load_workbook
from openpyxl.utils.dataframe import dataframe_to_rows
import math
import requests


# 批量获取文章信息并保存到excel
class CSDNArticleExporter:
    def __init__(self, username, cookies, Referer, page, size, filename):
        self.username = username
        self.cookies = cookies
        self.Referer = Referer
        self.size = size
        self.filename = filename
        self.page = page

    def get_articles(self):
        url = "https://blog.csdn.net/community/home-api/v1/get-business-list"
        params = {
            "page": {self.page},
            "size": {self.size},
            "businessType": "blog",
            "username": {self.username}
        }
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3',
            'Cookie': self.cookies,  # Setting the cookies string directly in headers
            'Referer': self.Referer
        }

        try:
            response = requests.get(url, params=params, headers=headers)
            response.raise_for_status()  # Raises an HTTPError if the response status code is 4XX or 5XX
            data = response.json()
            return data.get('data', {}).get('list', [])
        except requests.exceptions.HTTPError as e:
            print(f"HTTP错误: {e.response.status_code} {e.response.reason}")
        except requests.exceptions.RequestException as e:
            print(f"请求异常: {e}")
        except json.JSONDecodeError:
            print("解析JSON失败")
        return []

    def export_to_excel(self):
        df = pd.DataFrame(self.get_articles())
        df = df[['title', 'url', 'postTime', 'viewCount', 'collectCount', 'diggCount', 'commentCount']]
        df.columns = ['文章标题', 'URL', '发布时间', '阅读量', '收藏量', '点赞量', '评论量']
        # df.to_excel(self.filename)
        # 下面的代码会让excel每列都是合适的列宽，如达到最佳阅读效果
        # 你只用上面的保存也是可以的
        # Create a new workbook and select the active sheet
        wb = Workbook()
        sheet = wb.active
        # Write DataFrame to sheet
        for r in dataframe_to_rows(df, index=False, header=True):
            sheet.append(r)
        # Iterate over the columns and set column width to the max length in each column
        for column in sheet.columns:
            max_length = 0
            column = [cell for cell in column]
            for cell in column:
                try:
                    if len(str(cell.value)) > max_length:
                        max_length = len(cell.value)
                except:
                    pass
            adjusted_width = (max_length + 5)
            sheet.column_dimensions[column[0].column_letter].width = adjusted_width
        # Save the workbook
        wb.save(self.filename)


class ArticleScores:
    def __init__(self, filepath):
        self.filepath = filepath

    @staticmethod
    def get_article_score(article_url):
        url = "https://shilin.csdn.net/trends/api/v1/get-article-score"
        # TODO: Replace with your actual headers
        headers = {
            "Accept": "application/json, text/plain, */*",
            "X-Ca-Key": "203930474",
            "X-Ca-Nonce": "b35e1821-05c2-458d-adae-3b720bb15fdf",
            "X-Ca-Signature": "gjeSiKTRCh8aDv0UwThIVRITc/JtGJkgkZoLVeA6sWo=",
            "X-Ca-Signature-Headers": "x-ca-key,x-ca-nonce",
            "X-Ca-Signed-Content-Type": "multipart/form-data",
        }
        data = {"url": article_url}
        try:
            response = requests.post(url, headers=headers, data=data)
            response.raise_for_status()  # This will raise an error for bad responses
            return response.json().get('data', {}).get('score', 'Score not found')
        except requests.RequestException as e:
            print(f"Request failed: {e}")
            return "Error fetching score"

    def get_scores_from_excel(self):
        df = pd.read_excel(self.filepath)
        urls = df['URL'].tolist()
        scores = [self.get_article_score(url) for url in urls]
        return scores

    def write_scores_to_excel(self):
        df = pd.read_excel(self.filepath)
        df['质量分'] = self.get_scores_from_excel()
        df.to_excel(self.filepath, index=False)


if __name__ == '__main__':
    total = 10  # 已发文章总数量
    # TODO:调整为你自己的cookies，Referer，CSDNid, headers
    cookies = 'uuid_tt_dd=10_20269523720'  # Simplified for brevity
    Referer = 'https://blog.csdn.net/2201_76004325?type=blog'
    CSDNid = '2201_76004325'
    t_index = math.ceil(total / 100) + 1  # 向上取整，半闭半开区间，开区间+1。
    # 获取文章信息
    # CSDNArticleExporter("待查询用户名", 2（分页数量，按总文章数量/100所得的分页数）,总文章数量仅为设置为全部可见的文章总数。
    # 100（最大单次查询文章数量不大于100）, 'score1.xlsx'（待保存数据的文件，需要和下面的一致）)
    for index in range(1, t_index):  # 文章总数
        filename = "score" + str(index) + ".xlsx"
        exporter = CSDNArticleExporter(CSDNid, cookies, Referer, index, 100, filename)  # Replace with your username
        exporter.export_to_excel()
        # 批量获取质量分
        score = ArticleScores(filename)
        score.write_scores_to_excel()
