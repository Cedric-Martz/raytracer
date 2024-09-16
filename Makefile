##
## EPITECH PROJECT, 2024
## B-OOP-400-STG-4-1-raytracer-cedric.martz
## File description:
## Makefile
##

SRC		=		./src/vector3D.cpp \
				./src/color.cpp \
				./src/main.cpp \
				./src/utilities.cpp \
				./src/interval.cpp \
				./src/readFileConf.cpp \
				./src/camera.cpp \
				./src/PrimitiveList.cpp \
				./src/ray.cpp	\
				./src/hitRecord.cpp \
				./src/AMaterial.cpp \
				./src/material.cpp	\
				./src/sphere.cpp \
				./src/boundingBox.cpp \
				./src/bvh.cpp \
				./src/plane.cpp \
				./src/APrimitive.cpp

CC 				=	g++

OBJ				=	$(SRC:.cpp=.o)

LIB_FLAGS		=   -lsfml-graphics -lsfml-window -lsfml-system -lconfig++

BINARY	=	raytracer

all:	$(BINARY)

$(BINARY): $(OBJ)
	g++ -o $(BINARY) $(SRC) $(LIB_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY)

re:	fclean all

.PHONY:	all re clean fclean