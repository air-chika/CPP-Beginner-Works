#include"pattern.h"
//	cout << "�������X�[�T�W�Z�V�Y\n"; ��
//	cout << "�������^�a�U�]�`�\�_\n"; 6(12)��ģ��
	//���������ռ����������
	//���˸�
	//char* ul, * ur, * dl, * dr, * up, * down, * left, * right;
	//���ϣ����ϣ����£����£����ϣ��ң���

char boardlinemodel::full[8][3]{ "bb","bb","bb","bb","bb","bb","bb","bb" };
char boardlinemodel::singleline[8][3]{ "��","��","��","��","��","��","��","��" };
char boardlinemodel::doubleline[8][3]{ "�X","�[","�^","�a","�U","�T","�U","�T" };
char boardlinemodel::highdoubleline[8][3]{ "�W","�Z","�]","�`","�U","��","�U","��" };
char boardlinemodel::widedoubleline[8][3]{ "�V","�Y","�\","�_","��","�T","��","�T" };
char boardlinemodel::fullcorners[8][3]{ "bb","bb","bb","bb","|","��"," |","��" };