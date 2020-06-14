#include "Engine.h"


Engine::Engine(const char* game_name, Configuration* config)
{
	const auto initialize_glfw = [this, game_name, config]()
	{
		expect(glfwInit() == GLFW_TRUE, "Failed to initialize GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		_window = glfwCreateWindow(config->screenWidth, config->screenHeight, game_name, NULL, NULL);
		expect(_window != nullptr, "Failed to create GLFW window.");
		glfwMakeContextCurrent(_window);
	};
	const auto initialize_glew = [this]()
	{
		glewExperimental = GL_TRUE;
		const GLenum init_result = glewInit();
		expect(glewInit() == GLEW_OK, (char*)glewGetErrorString(init_result));
	};
	const auto initialize_gl = [this]()
	{
		const auto gl_debug_message_callback = [](
			GLenum,
			GLenum type,
			GLuint,
			GLenum severity,
			GLsizei,
			const GLchar* message,
			const void*)
		{
			if(severity > GL_DEBUG_SEVERITY_NOTIFICATION)
			{
				fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
					(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
					type, severity, message);
				std::cout << glGetError() << std::endl;
			}
		};

		glEnable(GL_DEBUG_OUTPUT);

		glDebugMessageCallback(gl_debug_message_callback, 0);
		
		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_TRUE);
		glDepthFunc(GL_LESS);
		
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);
	};

	initialize_glfw();
	initialize_glew();
	initialize_gl();
}
Engine::~Engine()
{
}
void Engine::Simulate(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input)
{
	SimulateAI(_deltaTime, _assets, _scene, _config, _input);
	SimulatePhysics(_deltaTime, _assets, _scene, _config);
	Render(_deltaTime, _assets, _scene, _config);
}
void Engine::SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input)
{
	for(auto game_object : _scene->GetGameObjects())
		game_object->SimulateAI(_deltaTime, _assets, _scene, _config, _input);
}
void Engine::SimulatePhysics(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config)
{
	for(auto game_object : scene->GetGameObjects())
		game_object->SimulatePhysics(_deltaTime, assets, scene, config);
}
void Engine::Render(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config)
{
	const auto prepare = [this]()
	{
		glfwSwapBuffers(_window);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	};
	const auto render_gameobjects = [this, assets, config, scene, _deltaTime]()
	{
		for(auto game_object : scene->GetGameObjects())
		{
			game_object->Render(_deltaTime, assets, scene, config);
		}
	};
	const auto cleanup = [this]()
	{
		glBindVertexArray(0);
		glUseProgram(0);
	};

	prepare();
	render_gameobjects();
	cleanup();	
}

GLFWwindow* Engine::window() const
{
	return _window;
}