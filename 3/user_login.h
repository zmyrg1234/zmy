#pragma once
#ifndef _USER_LOGIN_H
#define _USER_LOGIN_H

/**
 * 本函数负责与文件交互而不与用户交互, 与用户的交互再control.h中
 * @return 如果返回-1 则表明登陆失败
 * @param username 用户名
 * @param password 密码
 */
struct UserAccount user_login(char* username, char* password);

/**
 * 本函数负责与文件交互而不与用户交互, 与用户的交互再control.h中
 * @return 如果返回-1 则表示创建失败
 * @param username 用户设置的用户名
 * @param password 用户设置的密码
 * @param password_confirm 用户输入确认密码
 */
struct UserAccount user_signup(char* username, char* password);

#endif // !_USER_LOGIN_H