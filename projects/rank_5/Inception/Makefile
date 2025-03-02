#	====================	DIRECTORIES			====================

SAFE = safety
SRC = srcs

#	====================	FILES				====================

NAME = inception
FILE = docker-compose.yml
SERVICES = nginx wordpress mariadb

#	====================	COMMANDS			====================

COMPOSE = docker compose

#	====================	FLAGS				====================

#	====================	COLORS				====================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
CYAN = \033[0;36m

B_RED = \033[1;31m
B_GREEN = \033[1;32m
B_BLUE = \033[1;34m
B_YELLOW = \033[1;33m
B_MAGENTA = \033[1;35m
B_CYAN = \033[1;36m

L_BLUE = \033[1;94m

RESET = \033[0m

#	====================	RULES      			====================

all: $(NAME)

$(NAME): volumes check_hosts
	$(COMPOSE) -f $(SRC)/$(FILE) up --build

volumes:
	@if [ ! -d "home/txisto-d/data/mariadb" ] && [ ! -d "home/txisto-d/data/wordpress;" ]; then \
	mkdir -p home/txisto-d/data/mariadb && mkdir -p home/txisto-d/data/wordpress; fi

check_hosts:
	@if ! grep -q "127.0.0.1       txisto-d.42.fr" /etc/hosts; then \
		echo "127.0.0.1 txisto-d.42.fr" | sudo tee -a /etc/hosts; \
	fi

clean:
	docker remove $(SERVICES) -f

fclean: clean
	sudo rm -rf home