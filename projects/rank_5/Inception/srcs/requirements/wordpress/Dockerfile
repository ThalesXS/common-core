FROM debian:bullseye

RUN apt update
RUN apt upgrade -y
RUN apt install -y php-fpm php-mysqli curl
RUN mkdir -p /run/php
RUN mkdir -p /var/www/html/wp-content/uploads
RUN chown -R www-data:www-data /run/php

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/.
COPY ./tools/wp-install.sh .
RUN chmod 777 wp-install.sh

EXPOSE 9000

ENTRYPOINT ["./wp-install.sh"]