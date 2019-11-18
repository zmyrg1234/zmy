#pragma once
#ifndef _USER_LOGIN_H
#define _USER_LOGIN_H

/**
 * �������������ļ������������û�����, ���û��Ľ�����control.h��
 * @return �������-1 �������½ʧ��
 * @param username �û���
 * @param password ����
 */
struct UserAccount user_login(char* username, char* password);

/**
 * �������������ļ������������û�����, ���û��Ľ�����control.h��
 * @return �������-1 ���ʾ����ʧ��
 * @param username �û����õ��û���
 * @param password �û����õ�����
 * @param password_confirm �û�����ȷ������
 */
struct UserAccount user_signup(char* username, char* password);

#endif // !_USER_LOGIN_H