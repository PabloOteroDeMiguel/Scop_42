# Scop_42
Install OpenGL with brew
    brew install glfw
    brew install glew

gcc -I/Users/potero-d/.brew/Cellar/glfw/3.3.9/include -I/Users/potero-d/.brew/Cellar/glew/2.2.0_1/include -L/Users/potero-d/.brew/Cellar/glfw/3.3.9/lib -lglfw -L/Users/potero-d/.brew/Cellar/glew/2.2.0_1/lib -lGLEW -framework Cocoa  -framework OpenGL -framework IOKit -framework CoreVideo -Imlx -Ilibft/ main.c

gcc -I//usr/local/Cellar/glfw/3.4/include -I/usr/local/Cellar/glew/2.2.0_1/include -L/usr/local/Cellar/glfw/3.4/lib -lglfw -L/usr/local/Cellar/glew/2.2.0_1/lib -lGLEW -framework Cocoa  -framework OpenGL -framework IOKit -framework CoreVideo -Imlx -Ilibft/ main.c

/usr/local/Cellar/glew/2.2.0_1/include

/usr/local/Cellar/glfw/3.4/include