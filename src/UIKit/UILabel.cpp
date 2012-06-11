#include "UILabel.h"
#include "UIColor.h"

#include <iostream>

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
        //std::wcout << L"UILabel drawRect: drawing text" << std::endl;

        RECT rect;

        HDC hDC = GetWindowDC(this->layer->_hWnd);

        // Create/setup font

        LOGFONT logFont;
        memset(&logFont, 0, sizeof(LOGFONT));  

        logFont.lfHeight = abs(((int)this->font.pointSize * GetDeviceCaps(hDC, LOGPIXELSY)) / 72); 
        //logFont.lfWeight = this->fontWeight;
        logFont.lfQuality = CLEARTYPE_QUALITY;
        logFont.lfCharSet = DEFAULT_CHARSET;

        HFONT hFont = CreateFontIndirect(&logFont);

        SelectObject(hDC, hFont);

        // Drawing actual text

        GetClientRect(this->layer->_hWnd, &rect);

        SetTextColor(hDC, this->textColor->colorRef);
        SetBkMode(hDC, TRANSPARENT);

        DrawText( hDC,
                  this->text.c_str(),
                  -1,
                  &rect,
                  this->textAlignment | DT_SINGLELINE | DT_NOCLIP );

        DeleteDC(hDC);

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