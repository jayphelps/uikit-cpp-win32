#include "UIKit/UIKit.h"

/**
 * An example of a basic UIViewController
 */
class ExampleViewController : public UIViewController
{
  public:

    /**
     * loadView() is called whenever the view property is accessed but a view
     * hasn't been set
     */
    void loadView()
    {
        OutputDebugString(L"AND BOOM");
        CGRect frame = CGRectMake(0, 0, 100, 200);
        UIView *mainView = (new UIView)->initWithFrame(frame);

        // Set the main view
        this->view = mainView;
    }

    /**
     * viewDidLoad() is called immediately after loadView() is called. To prevent
     * infinite recursion by accessing ->view in loadView() you should create
     * all subviews in here.
     */
    void viewDidLoad()
    {
        CGRect frame = CGRectMake(0, 0, 100, 200);
        UIView *anotherView = (new UIView)->initWithFrame(frame);

        this->view->addSubview(anotherView);
    }
};

/**
 * An example of a basic UIApplicationDelegate
 */
class ExampleApplicationDelegate : public UIApplicationDelegate
{
  public:

    /**
     * applicationDidFinishLaunching() is called automatically quite obviously
     * when the application setup is done and everything is ready. In here
     * you should create your window(s) and assign your rootViewController
     */
    void applicationDidFinishLaunching(UIApplication &application)
    {
        CGRect windowFrame = CGRectMake(0, 0, 100, 200);

        this->window = (new UIWindow)->initWithFrame(windowFrame);
        this->window->rootViewController = new ExampleViewController();

        this->window->makeKeyAndVisible();
    }
};

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prev_instance, wchar_t* command_line, int show_command)
{
    return UIApplicationMain<ExampleApplicationDelegate, UIApplication>();
}