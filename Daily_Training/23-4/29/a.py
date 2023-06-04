import requests
import parsel
import csv
import json
from fake_useragent import UserAgent

f = open('旅游景点.csv', mode='a', encoding='utf-8-sig', newline='')
csv_writer = csv.DictWriter(f,
                            fieldnames=['景区名字', '详情地址', '景区等级', '省份', '市区', '地址', '热度', '简介',
                                        '价格', '月销', '图片', '资讯', '评论'])
# csv_writer.writeheader()

co1 = 'QN1=00007f802eb44f5e99389b96; QN300=s=bing; QN99=6082; QunarGlobal=10.66.70.17_7b56d759_1876fba3297_4d3b|1681216430722; _i=VInJOQdYjc2qqpCqY5xy4zudIVpq; QN601=45b85685e3b5d4a974eb882fecd85b6c; QN269=1D52B710D86511EDBA87FA163E028184; QN48=52cbbe2f-132f-4a1e-bdf0-af134bd26139; fid=973c69d9-b4eb-418d-ba4c-293bd850ac18; QN57=16812164769340.5364826648143417; QN205=organic; QN277=organic; qunar-assist={"version":"20211215173359.925","show":false,"audio":false,"speed":"middle","zomm":1,"cursor":false,"pointer":false,"bigtext":false,"overead":false,"readscreen":false,"theme":"default"}; csrfToken=nnX2AhFJEYIjVbuxYeGt6NQEiq89Q9mu; _vi=XRZkAQgB2xKHLeum1S-SBC1fZ0qBLmwveHH9wiMuxN_2RVMxg_VdqHujK23nDO9iNPT9nrxfNy8pQLDe16ChEIrXMFf2SrNl5gCDRdqGNFeHxzWUaQTgZzQA-nfLcLFQFyR9f7MS1pAePtHVQIshjH0hIMudWfNDIXimKh2Rxcaa; Hm_lvt_15577700f8ecddb1a927813c81166ade=1682422583,1682425214,1682426171,1682640537; Hm_lpvt_15577700f8ecddb1a927813c81166ade=1682640537; QN271=d550f5b0-4314-4212-b3f1-45b4318a620a; __qt=v1|VTJGc2RHVmtYMStvNEJvWlE2SlhNbjV1T0dZU0U2U1ovaEoycjBMR25DbDBmc29obnNTT1A0bFNqM1dSeFVSMjNrWWZtcFpxM05Nd3dxU3FZNFQzcnl1Z3BCbzE5djd3RmI1WDZKb1lZRUZjSHErOGZtQnZCbkIyRCtGcVR5V3liQnBycWlQRlBWZ2NDUCtsN2RLRmlQTThxcEFSYmF2MSs5ZW1sV08xcHIwPQ==|1682640543776|VTJGc2RHVmtYMS9FaFhpT1BPSGRDVlRFNHVOSTBVeTdHU1EzYytNZ1c0TzBORVIxYTB3SlJUUk1KY2FkNnJmd2VIUWl3MFZyZ1pZUVFKdTNkT25QV3c9PQ==|VTJGc2RHVmtYMTg3UTF6bDBlS1lzY1g1TUhvdm54eG4wQ0N1KzI0Uzl3dHZqNG56VDhvYTYrbHBTRTJjb0p6Q21qRnJycUVrZGlEc1R6ZFRVT3NwZW04U2M1cFpRM3I0RUJ5L0pzOUxtZlNHeXMreisvRjlQcXdhTElYS0tJcy9IckhmR0hoQWVodjhCV2pSNTdpNkYweERSRmloWldVd2V5ZDJLb3FoM1I5ZFFUZ1BXTm9uTXo2c2dWNFQ4NDlJMjV6SzRPZG8vNEROWERVMVk3aVpPSWRhVFkxY2h3S3p6VmNiSDJJdjBDa080c1pHZ1hvWVRHbG53emhvcHZUYUFRb1phVzFsUm5IZklGYjhDY1dsSXdRRzgxcDBEU29tZ2hNRkpXRTdtRjU2YTV4aVozMVhsY0JlUWErUlI4SFpodUpZREQ4bWRReW5OK1o0T1FEaU4rRHhHV1RrZ2lpZ2JXREpFaFZxaGd3YVliUVp2UmlGS3VYc2U4ZjVaRFNrdEdVcFFlZ0k5T1VLR0dTVVVyckhGYkcwNjFpdW83YXNHZm5LZTRLeEhjVExpeHltaEVKZVk4ci8wbFRFV3hxbFRuZS9SVmIybGk4NzhLSUp2cGFpWjBNWGFRM3g2SnNMbERad0JWaEM0SDQ2ZlhIam9QWDd5dWlrWElXdS9KTk53Zml1L3ZwenRiSi93V0tEcFJhelF0NTk5NEtCRTZPYmR5SUxqbjJiSWdQUVFna0twVkxqOVYyVkJ2bDhuOGQvOTFQSWMvVGw4MnM5c2daa2lKV0g0ZXBTdUNYYWNkcGRWbHNWVFBPZ2RaYkE5UU8xT2JORjZFbmVhdmRLYUtySG0zblIzMVlCUXFiejNaNTY2SkF0R2NNbXJRRUY3RFVOUUx1cW1EbEtpQlhUTWxRMUd1YnRNZFo2N1dGTUd5ZVNiWENVM2lKQkMvRXFaL3BtZmxYS1ZpM0hybkpSTGludUVDZ1p4cGd3bVRpQU9pUHVCR2ZrN0JQVWwza2tTOThT; JSESSIONID=5E1F159AA03D0203C08C5D403E1EA37C; QN267=945637561ae075a24; ariaDefaultTheme=undefined; QN58=1682640536864|1682640545356|2'

ua = UserAgent()
for page in range(1, 335):
    print(
        '==========================================正在保存第{}页数据===================================================='.format(
            page))
    url = 'https://piao.qunar.com/ticket/list_中国.html?from=mps_search_suggest_c&keyword=中国&page={}'.format(page)
    headers = {
        'user-agent': ua.random,
        'Cookie': co1,
    }
    response = requests.get(url=url, headers=headers)
    if str(response) == '<Response [404]>':
        page = page - 1
        break
    selector = parsel.Selector(response.text)
    lis = selector.css('#search-list .sight_item')
    dit = {}
    print(len(lis), '++++++++++')
    for li in lis:
        title = li.css('.sight_item_caption a::attr(title)').get()  # 景区名字
        dit['景区名字'] = title.strip()
        d_url = li.css('.sight_item_caption a::attr(href)').get()  # 详情
        detail_url = 'https://piao.qunar.com' + d_url
        dit['详情地址'] = detail_url.strip()
        res = requests.get(url=detail_url, headers=headers)
        if str(res) == '<Response [404]>':
            break
        sel = parsel.Selector(res.text)
        info = sel.css('.mp-charact-content .mp-charact-desc p::text').get()
        dit['资讯'] = info.strip()

        comm = sel.css('.mp-comments-head a::attr(href)').get()
        sightId = comm.split('=')[-1]
        comm_url = f'https://piao.qunar.com/ticket/detailLight/sightCommentList.json?sightId={sightId}&index=1&page=1&pageSize=10&tagType=0'
        comm_content = ''
        comm_res = requests.get(url=comm_url, headers=headers)
        try:
            comm_json = json.loads(comm_res.text)
            comm_content = comm_json['data']['commentList'][0]['content']
        except:
            comm_content = '暂未评价'
        dit['评论'] = comm_content

        image_url = li.css('.sight_item_show img::attr(data-original)').get()
        dit['图片'] = image_url.strip()

        level = li.css('.sight_item_info .level::text').get()  # 景区等级
        if level is None:
            level = '暂未评级'
        dit['景区等级'] = level
        area = li.css('.area a::attr(title)').get()  # 地区
        dit['省份'] = area.split('·')[0] + '省'
        dit['市区'] = area.split('·')[1] + '市'
        address = li.css('.address span::attr(title)').get()  # 地址
        dit['地址'] = address.strip()
        string = li.css('.product_star_level em::attr(title)').get()  # 热度
        star_level = float(string.strip('热度: '))
        dit['热度'] = star_level
        intro = li.css('.intro::attr(title)').get()  # 简介
        dit['简介'] = intro
        price = li.css('.sight_item_price em::text').get()  # 价格
        dit['价格'] = price
        hot_num = li.css('.hot_num::text').get()  # 月销
        dit['月销'] = hot_num
        csv_writer.writerow(dit)
        print(dit)
