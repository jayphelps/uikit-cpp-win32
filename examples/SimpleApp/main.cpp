#include "UIKit/UIKit.h"

LRESULT CALLBACK WndProcedure( HWND hWnd,
                                              UINT msg,
                                              WPARAM wParam,
                                              LPARAM lParam ) {
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

HINSTANCE hInstance;

BOOL initApplication(HINSTANCE hinstance) {
    WNDCLASSEX wcx; 
 
    // Fill in the window class structure with parameters 
    // that describe the main window. 
 
    wcx.cbSize = sizeof(wcx);          // size of structure 
    wcx.style = NULL;                   // redraw if size changes 
    wcx.lpfnWndProc = WndProcedure;     // points to window procedure 
    wcx.cbClsExtra = 0;                // no extra class memory 
    wcx.cbWndExtra = 0;                // no extra window memory 
    wcx.hInstance = hinstance;         // handle to instance 
    wcx.hIcon = NULL;             // predefined app. icon 
    wcx.hCursor = NULL;                   // predefined arrow 
    wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);                  // white background brush 
    wcx.lpszMenuName =  NULL;    // name of menu resource 
    wcx.lpszClassName = L"MainWClass";  // name of window class 
    wcx.hIconSm = NULL;
 
    // Register the window class. 
 
    return RegisterClassEx(&wcx);
}

int fakeIt() {
    
    if ( !initApplication(hInstance)) {
        // Handle that shit
        NSLog(L"RegisterClassEx FAILED: %d", GetLastError());
    }

    HWND hWnd = CreateWindow( L"MainWClass",                // lpClassName
                                NULL,                    // lpWindowName
                                WS_OVERLAPPEDWINDOW,          // dwStyle
                                100,    // x
                                100,    // y
                                500,  // width
                                500, // height
                                NULL,                    // hWndParent
                                NULL,                    // hMenu
                                hInstance,               // hInstance
                                NULL );                  // lpParam

    if (!hWnd) {
        NSLog(L"CreateWindow FAILED: %d", GetLastError());
    }

    ShowWindow(hWnd, SW_SHOW); 
    UpdateWindow(hWnd); 



    HWND hWnd2 = CreateWindow( L"MainWClass",                // lpClassName
                                NULL,                    // lpWindowName
                                WS_CHILD,          // dwStyle
                                10,    // x
                                10,    // y
                                50,  // width
                                50, // height
                                hWnd,                    // hWndParent
                                NULL,                    // hMenu
                                hInstance,               // hInstance
                                NULL );                  // lpParam

    if (!hWnd2) {
        NSLog(L"CreateWindow FAILED: %d", GetLastError());
    }

    ShowWindow(hWnd2, SW_SHOW); 
    UpdateWindow(hWnd2); 

    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;

}

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
        CGRect frame = CGRectMake(10.0f, 10.0f, 300.0f, 300.0f);
        UIView *mainView = (new UIView)->initWithFrame(frame);

        mainView->backgroundColor = UIColor::blackColor();

        /*CGRect labelFrame = CGRectMake(50.0f, 50.0f, 50.0f, 50.0f);
        UILabel *labelView = (new UILabel)->initWithFrame(labelFrame);
        labelView->backgroundColor = UIColor::whiteColor();
        labelView->text = L"HELLO WORLD!";*/

        //mainView->addSubview(labelView);

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
        // Button

        /*CGRect buttonFrame = CGRectMake(10.0f, 10.0f, 50.0f, 50.0f);
        UIView *buttonView = (new UIView)->initWithFrame(buttonFrame);
        buttonView->backgroundColor = UIColor::redColor();*/

        //this->view->addSubview(buttonView);

        // Label

        
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
        CGRect windowFrame = CGRectMake(100.0f, 100.0f, 500.0f, 500.0f);

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

    ::hInstance = hInstance;
    return fakeIt();

    /*return UIApplicationMain< ExampleApplicationDelegate,
                              UIApplication >( hInstance,
                                               hPrevInstance,
                                               pCmdLine,
                                               nCmdShow );*/
}