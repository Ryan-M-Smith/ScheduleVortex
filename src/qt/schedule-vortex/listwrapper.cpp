//
// FILENAME: tasklist.cpp | Schedule Vortex
// DESCRIPTION: The source file for tasklist.hpp
// CREATED: 2023-02-07 @ 11:39 AM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#include "listwrapper.hpp"

ListWrapper::ListWrapper(QListWidget* listWidget):
	m_ListWidget(listWidget)
{}

ListWrapper::~ListWrapper() {
	delete m_ListWidget;
}

void ListWrapper::AddItem(const string& itemName) {
	m_Items.push_back(itemName);
	m_ListWidget->addItem(QString::fromStdString(itemName));
}

void ListWrapper::DeleteItem(unsigned int index) {
	m_Items.erase(m_Items.begin() + index);
	m_ListWidget->takeItem(index);
}

void ListWrapper::Clear() {
	m_Items.clear();
	m_ListWidget->clear();
}