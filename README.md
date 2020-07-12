# BatchRenderer
A 2D Rendering application that uses OpenGL as the graphics API. The application is capable of rendering a large number of 2D geometry in fewer draw calls. This is achieved by using batching. Multiple geometries are batched together and are drawn in a single draw call for better performance. This implementation can be useful whenever a large number of 2D geometry has to be drawn in a single frame. The application also supports

-Logging system used for debugging. Used spdlog as the logging library with an abstracted Log class.
-Event System to track & handle events in the application. Currently, Mouse, Keyboard, & Window events are supported.

To generate project files please run the batch script under scripts folder
