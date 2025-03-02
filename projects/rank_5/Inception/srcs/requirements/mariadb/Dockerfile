FROM debian:bullseye

RUN apt update
RUN apt upgrade -y
RUN apt install -y mariadb-server
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/.
RUN mkdir /run/mysqld
COPY tools/mariadb-run.sh .
RUN chmod 777 ./mariadb-run.sh

EXPOSE 3306

ENTRYPOINT ["./mariadb-run.sh"]