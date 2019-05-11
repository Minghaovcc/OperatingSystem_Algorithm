#ifndef PAGE_MANAGER
#define PAGE_MANAGER

struct page {
	//编号
	int id;
	//访问
	int visit = 0;
	//是否修改过
	bool alter = false;
};


struct page_frame {
	//编号
	int id;
	//对应页面
	page *page = nullptr;
};

enum missing {
	//页表命中
	no,
	//缺页中断
	missing_page,
	//缺页中断，页面置换
	missing_page_and_replace
};

const int page_frame_num = 20;

class page_manager {
public:
	page_manager();
	~page_manager();
	virtual missing require_frame(const int page_id,int &frame_id,const bool alter = false) = 0;

private:
	page_frame frames[page_frame_num];
};

#endif // !PAGE_MANAGER





