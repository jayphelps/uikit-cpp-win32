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
        NSLog(L"AND BOOM");
        UIView *mainView = (new UIView)->initWithFrame(CGRectMake(0, 0, 100, 200));

        mainView->backgroundColor = UIColor::blackColor();

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
        UIView *anotherView = (new UIView)->initWithFrame(CGRectMake(0, 0, 10, 40));
        
        //anotherView->backgroundColor = UIColor::redColor();

        //this->view->addSubview(anotherView);
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
        CGRect windowFrame = CGRectMake(100.0f, 100.0f, 800.0f, 600.0f);

        this->window = (new UIWindow)->initWithFrame(windowFrame);
        this->window->rootViewController = new ExampleViewController();
        this->window->backgroundColor = UIColor::redColor();

        this->window->makeKeyAndVisible();
    }
};

int WINAPI wWinMain( HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     wchar_t *pCmdLine,
                     int nCmdShow )
{
    return UIApplicationMain< ExampleApplicationDelegate,
                              UIApplication >( hInstance,
                                               hPrevInstance,
                                               pCmdLine,
                                               nCmdShow );
}