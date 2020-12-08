
// MFCTextEditorView.cpp : implementation of the CMFCTextEditorView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTextEditor.h"
#endif

#include "MFCTextEditorDoc.h"
#include "MFCTextEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTextEditorView

IMPLEMENT_DYNCREATE(CMFCTextEditorView, CEditView)

BEGIN_MESSAGE_MAP(CMFCTextEditorView, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCTextEditorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	//Команда для диалога
	ON_COMMAND(ID_APP_ABOUT, &CMFCTextEditorView::onFontDialog)
END_MESSAGE_MAP()

// CMFCTextEditorView construction/destruction

CMFCTextEditorView::CMFCTextEditorView() noexcept
{
	// TODO: add construction code here

}

CMFCTextEditorView::~CMFCTextEditorView()
{
}

BOOL CMFCTextEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CMFCTextEditorView printing


void CMFCTextEditorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCTextEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CMFCTextEditorView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMFCTextEditorView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

void CMFCTextEditorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCTextEditorView::onFontDialog() {
	//Стандартный диалог с шрифтами 
	CFontDialog dlg;
	if (dlg.DoModal() == IDOK) {
		memcpy(&m_lf, dlg.m_cf.lpLogFont, sizeof(LOGFONT));
		//Создаем шрифт
		m_Font.CreateFontIndirect(&m_lf); 
		//Устанавливаем шрифт
		this->SetFont(&m_Font);
	}
}

void CMFCTextEditorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCTextEditorView diagnostics

#ifdef _DEBUG
void CMFCTextEditorView::AssertValid() const
{
	CEditView::AssertValid();
}

void CMFCTextEditorView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMFCTextEditorDoc* CMFCTextEditorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTextEditorDoc)));
	return (CMFCTextEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTextEditorView message handlers
