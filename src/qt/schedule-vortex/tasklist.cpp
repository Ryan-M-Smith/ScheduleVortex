//
// FILENAME: tasklist.cpp | Schedule Vortex
// DESCRIPTION: The source file for tasklist.hpp
// CREATED: 2023-02-07 @ 11:39 AM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#include "tasklist.hpp"

TaskList::TaskList(QListWidget* taskList):
	m_TaskList(taskList)
{}

TaskList::~TaskList() {
	delete m_TaskList;
}

void TaskList::AddTask(const string& taskName) {
	m_Tasks.push_back(taskName);
	m_TaskList->addItem(QString::fromStdString(taskName));
}