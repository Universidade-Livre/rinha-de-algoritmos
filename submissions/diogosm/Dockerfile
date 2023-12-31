FROM python:3.8

WORKDIR /app
COPY . /app

RUN pip install numba

CMD ["bash", "-c", "time --verbose python3 problema-1.py < /app/exemplo_03.txt"]
