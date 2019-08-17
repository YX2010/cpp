#include <set>
#include "message.h"
#include "folder.h"

void Folder::addMeg(Message *m){
	message_.insert(*m);	// 将给定Message添加至我们的Message列表中
	m->save(this);				// 将本Folder添加至m的列表中
}

void Folder::remMeg(Message *m)[
	message_.erase(*m);		// 将给定的Message从我们的Message列表中删除
	m->remove(this);			// 将本Folder从m的Folder集合中删除
]

//
// 将本Folder添加至指向f的Messag中
void Folder::add_to_Message(const Folder& f){
	for (auto m : f.message_){
		m->save(*this)
	}
}

//
//
void Folder::remove_from_Message(){
	for (auto m : messages_){
		f->remove(*thi);
	}
}

Folder::~Folder(){
	remove_from_Message();
}

Folder& operator=(const Folder &rhs){
	remove_from_Message();
	message_ = rhs.message_;
	add_to_Message();
	return *this;
}

void swap(Folder &lhs, Folder &rhs){
	using std::swap;
	
	for(auto m : lhs.message_){
		m->remove(&lhs);
	}

	for (auto m : rhs.message_){
		m->remove(&rhs);
	}
	swap(lhs.message_, rhs.message_);

	for (auto m : lhs.message_){
		m->save(&lhs);
	}
	for (auto m : rhs.message_){
		m->save(&rhs);
	}
}
