#ifndef CONSOLES_CONSOLEUI_H
#define CONSOLES_CONSOLEUI_H

#include "console.h"

// Generic UI building blocks derived from Console (header-inline, 0x48c710-0x48e1a0).

extern int consoleArtFrameCount;	// NOTE: placeholder name
extern XColor *transparentColor;	// NOTE: placeholder name

//==================================================================
// ConsoleTitle
//==================================================================

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_)
		: Console(parent,title_.size(),1,0,0,font,false,-1)
		, title	(title_)
		, align	(align_)
	{
		setFgColor(consoleDefaultColor);
		print(0,0,title);
	};

	string title;
	int align;	// 0..4, see Console::setTitle()
};

//==================================================================
// ConsoleArt
//==================================================================

class ConsoleArt : public Console
{
public:
	ConsoleArt(XConsole *parent, AsciiImage *art, int x, int y, bool hidden, int layer, int frame, const Pos &offset_, int width, int height)
		: Console(parent,1,1,x,y,4,hidden,layer)
		, offset	(offset_)
	{
		if (offset.x == -1)
			image.copy(art);
		else
			image.copyRegion(art,4,&offset,width,height);

		if (width && height)
			resize(width,height);
		else
			resize(image.layers.front()->getWidth(),image.layers.front()->getHeight());

		if (frame != -1)
			drawArt(frame);
	};
	ConsoleArt(XConsole *parent, const string &file, int x, int y, bool hidden, int layer, int frame, const Pos &offset_, int width, int height)
		: Console(parent,1,1,x,y,4,hidden,layer)
		, offset	(offset_)
	{
		if (!image.load(file,4,&offset,width,height))
		{
			logError("ConsoleArt()","Failed to load art: " + file);
			image.layers.push_back(new XBuffer(getWidth(),getHeight(),Glyph(4)));
		}
		else
		{
			if (width && height)
				resize(width,height);
			else
				resize(image.layers.front()->getWidth(),image.layers.front()->getHeight());

			if (frame != -1)
				drawArt(frame);
		}
	};
	virtual ~ConsoleArt() {};

	virtual int getFrame() { return consoleArtFrameCount; };
	virtual void trigger(const string &command, int value) { ((Console*)getParent())->trigger(command,value); };

	void drawArt(int layer)
	{
		int first, last;
		if (layer == -1)
		{
			first = 0;
			last = image.layers.size() - 1;
		}
		else
			first = last = layer;

		XBuffer *console = getBuffer();
		for (int i = first; i <= last; i++)
		{
			if (i >= image.layers.size())
			{
				logError("ConsoleArt::drawArt()","Art does not contain layer " + intToString(i));
				return;
			}

			XBuffer *art = image.layers[i];
			if (i == 0)
				console->copy(art);
			else
			{
				for (int x = 0; x < art->getWidth(); x++)
				{
					for (int y = 0; y < art->getHeight(); y++)
					{
						if (*art->get(x,y)->getBg() != *transparentColor)
							*console->get(x,y) = *art->get(x,y);
					}
				}
			}
		}
	};

	AsciiImage image;
	Pos offset;
};

//==================================================================
// CArtAnimated
//==================================================================

class CArtAnimated : public ConsoleArt
{
public:
	CArtAnimated(XConsole *parent, AsciiImage *art, int x, int y, bool hidden, int unknown84_, int layer, int frame, const Pos &offset_, int width, int height)
		: ConsoleArt(parent,art,x,y,hidden,layer,frame,offset_,width,height)
		, unknown84	(unknown84_)
	{
		initialize();
	};
	CArtAnimated(XConsole *parent, const string &file, int x, int y, bool hidden, int unknown84_, int layer, int frame, const Pos &offset_, int width, int height)
		: ConsoleArt(parent,file,x,y,hidden,layer,frame,offset_,width,height)
		, unknown84	(unknown84_)
	{
		initialize();
	};
	virtual ~CArtAnimated() {};

	void initialize()	// NOTE: placeholder name
	{
		setArtFgColor(consoleDefaultColor);
		setArtBgColor(consoleDefaultColor);
	};

	int unknown84;
};

//==================================================================
// CText
//==================================================================

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer)
		: Console(parent,maxWidth ? minInt(text_.size(),maxWidth) : text_.size(),1,pos.x,pos.y,font,false,layer)
		, text	(text_)
	{
		print(0,0,text);
	};

	string text;
};

//==================================================================
// CTextButton
//==================================================================

class CTextButton : public Console
{
public:
	CTextButton(XConsole *parent, const Pos &pos, int width, const string &text_, int font, int align)
		: Console(parent,width,1,pos.x,pos.y,font,false,-1)
		, text	(text_)
	{
		switch (align)
		{
			case 0: printAligned(0,0,align,text); break;
			case 1: printAligned(width / 2,0,align,text); break;
			case 2: printAligned(width - 1,0,align,text); break;
		}
	};

	string text;
};

//==================================================================
// CTextInput
//==================================================================

class CTextInput : public Console
{
public:
	CTextInput(XConsole *parent, int x, int y, int width, int font, bool hidden, bool unknown8c_, int unknownAc_, int unknownB4_, int unknownB8_, int unknownBc_, const char *unknownC0_, int unknownDc_)
		: Console(parent,width,1,x,y,font,hidden,-1)
		, unknown8c	(unknown8c_)
		, unknown90	(0)
		, unknown94	(false)
		, unknown95	(false)
		, unknownA8	(false)
		, unknownA9	(false)
		, unknownAc	(unknownAc_)
		, unknownB0	(0)
		, unknownB4	(unknownB4_)
		, unknownB8	(unknownB8_)
		, unknownBc	(unknownBc_)
		, unknownDc	(unknownDc_)
		, unknownE0	(0)
	{
		if (unknownC0_)
			unknownC0 = unknownC0_;
		clear();
	};

	virtual void inputMouse(int x, int y);

	void clear()	// NOTE: placeholder name
	{
		XConsole::clear();
		text.clear();
		cursor = 0;
	};
	void setUnknown98(const vector<int> &unknown98_) { unknown98 = unknown98_; };	// NOTE: placeholder name
	void setUnknownA9(bool unknownA9_) { unknownA9 = unknownA9_; };	// NOTE: placeholder name
	void setText(const char *text_)	// NOTE: placeholder name
	{
		text = text_;
		cursor = text.size();
	};
	void setUnknownBc(int unknownBc_, const char *unknownC0_)	// NOTE: placeholder name
	{
		unknownBc = unknownBc_;
		unknownC0 = unknownC0_;
	};
	void setUnknown95(bool unknown95_) { unknown95 = unknown95_; };	// NOTE: placeholder name
	void setUnknownAa() { unknownAa = true; };	// NOTE: placeholder name

	string text;
	int cursor;
	bool unknown8c;
	int unknown90;
	bool unknown94;
	bool unknown95;
	vector<int> unknown98;
	bool unknownA8;
	bool unknownA9;
	bool unknownAa;
	int unknownAc;
	int unknownB0;
	int unknownB4;
	int unknownB8;
	int unknownBc;
	string unknownC0;
	int unknownDc;
	int unknownE0;
};

//==================================================================
// CTemp
//==================================================================

class CTemp : public Console
{
public:
	CTemp(XConsole *parent, const Pos &pos, int width, int height, int font, int layer)
		: Console(parent,width,height,pos.x,pos.y,font,false,layer)
	{};
};

//==================================================================
// CCloseButton
//==================================================================

class CCloseButton : public CTextButton
{
public:
	CCloseButton(XConsole *parent, const XColor &color, int command_)
		: CTextButton(parent,Pos(parent->getWidth() - 1 - (parent->isTileFont() ? 1 : 2),parent->getHeight() - 1),1,string("X"),2,0)
	{
		command = command_;
		setHidden(true);
		setFgColor(0,0,color);
	};

	virtual bool mouseEnter()
	{
		if (!keyMap->hasCommand(command))
			return false;
		animate("A_ButtonHover_Begin_CLOSE_HOV");
		return true;
	};
	virtual void mouseLeave()
	{
		if (!keyMap->hasCommand(command))
			return;
		engine->killGroup("fadein");
		animate("A_ButtonHover_End_CLOSE_HOV");
	};
	virtual bool input(void *event);

	int command;
};

//==================================================================
// CInterfaceMsg
//==================================================================

extern Rect interfaceMsgRect;	// NOTE: placeholder name

class CInterfaceMsg : public Console
{
public:
	CInterfaceMsg(XConsole *parent)
		: Console(parent,interfaceMsgRect,0,true,-1)
	{
		unknown80 = -1;
		unknown84 = true;
	};
	virtual ~CInterfaceMsg()
	{
		clear();
	};

	virtual void update();
	virtual void close();

	void clear()	// NOTE: placeholder name
	{
		deleteVector(messages);
		unknown80 = -1;
	};
	void refresh()	// NOTE: placeholder name
	{
		if (messages.empty())
			return;
		if (unknown84 || unknown80 == 0)
			close();
		else
			show(0);
	};
	void show(int index);	// NOTE: placeholder name

	int unknown6c;
	vector<Console*> messages;
	int unknown80;
	bool unknown84;
};

//==================================================================
// CListOption
//==================================================================

class CListOption : public Console
{
public:
	CListOption(XConsole *parent, int x, int y, int width, const string &text, int font, bool hidden, int unknown6c_, int unknown70_, bool selectable_, int unknown78_, int unknown7c_)
		: Console(parent,width,1,x,y,font,hidden,-1)
	{
		unknown6c = unknown6c_;
		unknown70 = unknown70_;
		selectable = selectable_;
		unknown78 = unknown78_;
		unknown7c = unknown7c_;
		print(0,0,text);
	};

	virtual bool mouseEnter()
	{
		if (!selectable)
			return false;
		animate("A_ButtonHover_Begin_LIST_HOV_OK");
		return true;
	};
	virtual void mouseLeave()
	{
		engine->killGroup("fadein");
		animate("A_ButtonHover_End_LIST_HOV_OK");
	};
	virtual bool input(void *event);
	virtual void render();

	void draw();	// NOTE: placeholder name

	int unknown6c;
	int unknown70;
	bool selectable;
	int unknown78;
	int unknown7c;
};

//==================================================================
// CList
//==================================================================

class CList;
extern CList *activeList;	// NOTE: placeholder name
extern XColor *listCloseColor;	// NOTE: placeholder name



class CList : public Console
{
public:
	CList(XConsole *parent, const Pos &pos, string title, int unknown74_, const vector<string> &options_, int maxVisible, int font, void (*callback_)(int,const string&), int unknownC4_, int layer, bool unknown9c_, bool unknown9d_, vector<bool> *enabled_, vector<int> *unknownA4_, vector<int> *unknownA8_, bool noClose_)
		: Console(parent,1,1,pos.x,pos.y,font,false,layer)
		, unknown74		(unknown74_)
		, options		(options_)
		, unknown94		(1)
		, unknown98		(0)
		, unknown9c		(unknown9c_)
		, unknown9d		(unknown9d_)
		, noClose		(noClose_)
		, enabled		(enabled_)
		, unknownA4		(unknownA4_)
		, unknownA8		(unknownA8_)
		, callback		(callback_)
		, unknownC0		(false)
		, unknownC4		(unknownC4_)
		, unknownC8		(0)
		, unknownCc		(0)
		, moreOption	(NULL)
	{
		activeList = this;
		if (0) {}	// NOTE: emits nothing; shifts register rotation to match
		maxLength = 0;
		for (unsigned int i = 0; i < options.size(); i++)
		{
			if (options[i].size() > maxLength)
				maxLength = options[i].size();
		}
		numVisible = minInt(options.size(),maxVisible);
		resize(maxInt(title.size() + 3,maxLength + 10),numVisible + 4);
		optionWidth = getWidth() - 9;

		setTitle(new ConsoleTitle(this,title,0,2));

		for (int i = 0, y = 2; i < numVisible; i++, y++)
		{
			listOptions.push_back(new CListOption(this,7,y,optionWidth,options[i],font,false,i,0,enabled ? (*enabled)[i] : true,unknownA4 ? (*unknownA4)[i] : 0,unknownA8 ? (*unknownA8)[i] : -1));
			listOptions.back()->draw();
			updateScroll();
		}
		if (options.size() > numVisible)
		{
			moreOption = new CListOption(this,7,getHeight() - 2,optionWidth,options[numVisible],font,false,0,1,1,0,-1);
			moreOption->draw();
		}

		animate("CList_Border");
		keyMap->registerConsole(0x12,this,noClose ? -1 : 270,0);
		unknown60 = 1;

		if (!noClose)
		{
			closeButton = new CCloseButton(this,*listCloseColor,0x12);
			closeButton->setHidden(false);
		}
	};
	virtual ~CList()
	{
		activeList = NULL;
		delete enabled;
		delete unknownA4;
		delete unknownA8;
	};

	virtual void update();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void close();

	void updateScroll();	// NOTE: placeholder name
	int getUnknown74() { return unknown74; };	// NOTE: placeholder name
	CListOption *getOption(int index) { return listOptions[index]; };	// NOTE: placeholder name
	void setUnknownC0(bool unknownC0_) { unknownC0 = unknownC0_; };	// NOTE: placeholder name
	void cancel() { callback(unknown74,string("")); };	// NOTE: placeholder name

	int unknown6c;
	CCloseButton *closeButton;
	int unknown74;
	vector<string> options;
	unsigned int maxLength;
	int optionWidth;
	int numVisible;
	int unknown94;
	int unknown98;
	bool unknown9c;
	bool unknown9d;
	bool noClose;
	vector<bool> *enabled;
	vector<int> *unknownA4;
	vector<int> *unknownA8;
	vector<CListOption*> listOptions;
	void (*callback)(int,const string&);
	bool unknownC0;
	int unknownC4;
	int unknownC8;
	int unknownCc;
	CListOption *moreOption;
};

#endif
