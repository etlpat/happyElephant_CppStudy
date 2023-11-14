// 队列(Queue)
//
//
// (1)概念
//	队列：队列是一种操作受限的线性表，只允许在一端进行插入，在另一端进行删除
//	队头：只允许在队头进行出队
//	队尾：只允许在队尾进行入队
//
// 
// (2)特点
//	队列的特点：先进先出，后进后出
//				first in first out (FIFO)
//	
//
// (3)基本操作
//	initQueue(&Q)：初始化队列
//	destroyQueue(&Q)：销毁队列
//	enQueue(&Q, elem)：入队
//	deQueue(&Q, &elem)：出队
//	getHead(&Q, &elem)：读取队头元素
//	......