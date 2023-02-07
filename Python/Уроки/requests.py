#pip install requests
import requests

url = 'https://yang.yandex-team.ru/tasks'
query = requests.get(url)
if query.status_code != 200:
    pass
else:
    print(query.text)





#try:
#    result = requests.get(self.url)
#    result.raise_for_status()
#    return result.text
#except(requests.RequestException, ValueError):
#    print('Server error')
#    return False