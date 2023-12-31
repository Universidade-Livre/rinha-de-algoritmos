FROM python:3.8

WORKDIR /app
COPY . /app

RUN pip install numba
#RUN apt-get update && apt-get install -y bc

CMD ["bash", "-c", "time python3 problema-1.py < /app/exemplo_03.txt"]
