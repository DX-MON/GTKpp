#include "Globals.h"
#include "GTK++.h"

GTKTextView::GTKTextView(GTKWidget *Parent, int Width, int Height)
{
	Widget = gtk_text_view_new();
	Container = GTK_CONTAINER(Widget);
	TextView = GTK_TEXT_VIEW(Container);
	SetParent(Parent);
	gtk_widget_set_size_request(Widget, Width, Height);
	TextBuffer = new GTKTextBuffer();
	gtk_text_view_set_buffer(TextView, (GtkTextBuffer *)TextBuffer->GetBuffer());
}

void GTKTextView::SetParent(GTKWidget *Parent)
{
	((GTKContainer *)Parent)->AddChild(this);
}

void GTKTextView::ClearText()
{
	TextBuffer->ClearText();
}

void GTKTextView::AddText(char *Text)
{
	TextBuffer->AddTextToEnd(Text);
}