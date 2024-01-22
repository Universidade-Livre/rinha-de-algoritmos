FROM bash:latest

RUN apk add --no-cache bash

COPY problema-1.sh /app/problema-1.sh

RUN chmod +x /app/problema-1.sh

WORKDIR /app

CMD ["./problema-1.sh"]