
// MFCTextEditorView.h : interface of the CMFCTextEditorView class
//

#pragma once


class CMFCTextEditorView : public CEditView
{

protected:
	LOGFONT m_lf;
	CFont m_Font;

public:
	afx_msg void onFontDialog();
protected: // create from serialization only
	CMFCTextEditorView() noexcept;
	DECLARE_DYNCREATE(CMFCTextEditorView)

// Attributes
public:
	CMFCTextEditorDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCTextEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCTextEditorView.cpp
inline CMFCTextEditorDoc* CMFCTextEditorView::GetDocument() const
   { return reinterpret_cast<CMFCTextEditorDoc*>(m_pDocument); }
#endif

