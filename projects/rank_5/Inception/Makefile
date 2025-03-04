#	====================	COMMANDS			====================

COMPOSE = docker compose

#	====================	RULES      			====================

all: up

up: build check_hosts
	docker compose --file srcs/docker-compose.yml up

re: down build up

fullre: fclean up

stop:
	docker compose --file srcs/docker-compose.yml stop

down:
	docker compose --file srcs/docker-compose.yml down

logs:
	docker compose --file srcs/docker-compose.yml logs

ps:
	docker compose --file srcs/docker-compose.yml ps

restart:
	docker compose --file srcs/docker-compose.yml restart

check_hosts:
	@if ! grep -q "127.0.0.1 $(USER).42.fr" /etc/hosts; then \
		echo "127.0.0.1 $(USER).42.fr" | sudo tee -a /etc/hosts; \
	fi

volumes:
	@if [ ! -d "/home/$(USER)/data/mariadb" ] && [ ! -d "/home/$(USER)/data/wordpress;" ]; then \
	mkdir -p /home/$(USER)/data/mariadb && mkdir -p /home/$(USER)/data/wordpress; fi

build: volumes
	docker compose --file srcs/docker-compose.yml build
	
clean:
	docker system prune -a

volume_free:
	docker volume rm srcs_v_db
	docker volume rm srcs_v_web
	sudo rm -rf /home/$(USER)/data

fclean: down clean volume_free
