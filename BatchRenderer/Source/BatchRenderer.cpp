#include <iostream>

#include "BRLayer.h"
#include "GLCore.h"
using namespace GLCore;
class BatchRendererApp : public Application
{
public:
    BatchRendererApp(const std::string& i_Name, uint32_t i_Width, uint32_t i_Height):Application(i_Name,i_Width,i_Height)
    {
        PushLayer(new BRLayer());
    }
};

int main()
{
    std::unique_ptr<BatchRendererApp> app = std::make_unique<BatchRendererApp>("BatchRenderer",1280,720);
    app->Run();
    _CrtDumpMemoryLeaks();
}


