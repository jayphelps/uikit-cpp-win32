#include "UILabel.h"
#include "UIColor.h"

#include <iostream>

class Fucker : public std::auto_ptr<UIView> {
  public:
    ~Fucker() {
        std::wcout << L"IM GONE" << std::endl;
    }

    void kickDog() {
        std::wcout << L"IM KICKING THE FUCKINGDOG" << std::endl;
    }
};

UILabel::UILabel()
    : textAlignment(UITextAlignmentLeft) {
    this->textColor = UIColor::blackColor();
    this->font = UIFont::systemFontOfSize(12.0f);
}

UILabel::~UILabel() {
    
}

UILabel * UILabel::initWithFrame(CGRect frame) {
    this->_initWithFrame(frame);
    this->backgroundColor = UIColor::whiteColor();
    return this;
}

void UILabel::drawRect(CGRect recter) {
    /*
    CGContextSaveGState(UIGraphicsGetCurrentContext());
    CGContextSetShadowWithColor(UIGraphicsGetCurrentContext(), offset, 0, _shadowColor.CGColor);
    
    // finally, draw the real label
    UIColor *drawColor = (_highlighted && _highlightedTextColor)? _highlightedTextColor : _textColor;
    [drawColor setFill];
    [self drawTextInRect:drawRect];
    
    CGContextRestoreGState(UIGraphicsGetCurrentContext());
    */

    /*RECT rc;

    GetClientRect(this->hWnd, &rc);

    //SetBkColor(this->hdcMem, this->backgroundColor);
    //SetBkMode(this->hdcMem, TRANSPARENT);
  
   
    LOGFONT logFont;
    memset(&logFont, 0, sizeof(LOGFONT));  

    logFont.lfHeight = abs((this->fontSize * GetDeviceCaps(this->hdcMem, LOGPIXELSY)) / 72); 
    logFont.lfWeight = this->fontWeight;  
    logFont.lfQuality = CLEARTYPE_QUALITY;
    logFont.lfCharSet = DEFAULT_CHARSET;   

    HFONT hFont = CreateFontIndirect(&logFont);

    SelectObject(this->hdcMem, hFont);

    //UINT lineType = (this->multiLine) ? DT_WORDBREAK : DT_VCENTER;

    SetTextColor(this->hdcMem, this->textColor);

    DrawText( this->hdcMem,
              this->text,
              wcslen(this->text),
              &rc,
              this->textAlign | lineType | DT_WORD_ELLIPSIS );*/

    if ( !this->text.empty() ) {
        std::wcout << L"UILabel drawRect: drawing text" << std::endl;

        RECT rect;

        HDC hDC = GetWindowDC(this->layer->_hWnd);

        // Create/setup font

        LOGFONT logFont;
        memset(&logFont, 0, sizeof(LOGFONT));  

        logFont.lfHeight = abs((this->font.pointSize * GetDeviceCaps(hDC, LOGPIXELSY)) / 72); 
        //logFont.lfWeight = this->fontWeight;
        logFont.lfQuality = CLEARTYPE_QUALITY;
        logFont.lfCharSet = DEFAULT_CHARSET;

        HFONT hFont = CreateFontIndirect(&logFont);

        SelectObject(hDC, hFont);

        // Drawing actual text

        GetClientRect (this->layer->_hWnd, &rect);

        SetTextColor(hDC, this->textColor->colorRef);
        SetBkMode(hDC, TRANSPARENT);

        DrawText( hDC,
                  this->text.c_str(),
                  -1,
                  &rect,
                  this->textAlignment | DT_SINGLELINE | DT_NOCLIP );

        DeleteDC(hDC);

        Fucker *foo = new Fucker();

        foo->kickDog();

    } else {
        std::wcout << L"UILabel drawRect: text is empty" << std::endl;
    }
}

std::wstring UILabel::getText() {
    return this->_text;
}

void UILabel::setText(std::wstring value) {
    this->_text = value;
    this->needsDisplay = YES;
}

UIColor * UILabel::getTextColor() {
    return this->_textColor;
}

void UILabel::setTextColor(UIColor *value) {
    this->_textColor = value;
    this->needsDisplay = YES;
}

UIColor * UILabel::getShadowColor() {
    return this->_shadowColor;
}

void UILabel::setShadowColor(UIColor *value) {
    this->_shadowColor = value;
    this->needsDisplay = YES;
}

CGSize UILabel::getShadowOffset() {
    return this->_shadowOffset;
}

void UILabel::setShadowOffset(CGSize value) {
    this->_shadowOffset = value;
    this->needsDisplay = YES;
}