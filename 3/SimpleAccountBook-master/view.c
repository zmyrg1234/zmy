#pragma once
#include <stdio.h>

/**
 * 打印菜单栏
 */
void print_start_menu() {
	printf("输入数字进行操作\n");
	printf("1. 新建账号.\n");
	printf("2. 登陆账号.\n");
	printf("3. 退出.\n");
}

/**
 * 打印菜单栏
 */
void print_operation_menu() {
	printf("输入数字进行操作\n");
	// @TODO: 输入对应的操作 参考 print_start_menu()
//	printf("3. 退出.\n");
}

/**
 * 打印欢迎信息
 */
void print_welcome() {
	// @TODO: 打印名字
	printf("欢迎使用简约记账本!\n");
}

/**
 * 当输入错误时提示用户
 */
void print_error_info() {
	printf("输入有误.\n");
}

/**
 * 打印"简约记账本"标题文字
 */
void print_title() {
	printf("简约记账本");
}