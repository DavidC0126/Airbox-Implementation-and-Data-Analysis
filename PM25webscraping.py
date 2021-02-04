import requests
import json
aqi_url = "https://data.epa.gov.tw/api/v1/aqx_p_219?offset=100&limit=200&api_key=3e88d339-be33-4f1f-a714-0f8e6be6027c" 
# 環保署環境資料開放平臺 試行版 https://data.epa.gov.tw/
# API 金鑰免費申請 ～
response = requests.get(aqi_url)
aqi = response.json()['records']
print(response.status_code)

### 200  正常回傳
### 404 回傳錯誤
print(type(response))
print(type(aqi))

for wa in aqi :
    print(wa["County"], wa["SiteName"], wa["Concentration"],wa["ItemEngName"],wa["MonitorDate"])
    
    
with open("data_pm25_忠明.txt", "w", encoding="utf-8") as file:
     for list in aqi:
        file.write(f'{list["County"]}, {list["SiteName"]}, {list["Concentration"]}, {list["ItemEngName"]}, {list["MonitorDate"]}\n')

file.close()
