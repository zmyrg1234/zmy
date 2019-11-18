#pragma once
#ifndef _USER_LOGIN_H
#define _USER_LOGIN_H

/**
 * �������������ļ������������û�����, ���û��Ľ�����control.h��
 * @return �������-1 �������½ʧ��
 * @param username �û���
 * @param password ����
 */
int user_login(char* username, char* password);

/**
 * �������������ļ������������û�����, ���û��Ľ�����control.h��
 * @return �������-1 ���ʾ����ʧ��
 * @param username �û����õ��û���
 * @param password �û����õ�����
 * @param password_confirm �û�����ȷ������
 */
int user_signup(char* username, char* password, char* password_confirm);

#endif // !_USER_LOGIN_H