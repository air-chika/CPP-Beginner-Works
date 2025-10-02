/*==============================================*/
/*时间：2022.4.15						        */
/*作者：KOHA at YLGD                             */
/*目标：大二春夏课程设计					        */
/*类型：控制台设计                                 */
/*==============================================*/

#include"SchoolUI.h"

int main()
{
	cursor::hideCursor();
	color::setall(color::明黄, color::黑);
	color::setback(color::黑);

	ifstream fin("ifm\\root.txt");
	if (!fin.is_open()) {
		cout << "丢失root文件";
		smpUI::getChoice(0);
		return 0;
	}
	char sSchoolFileName[50], sStudentFileName[50],sBackupFolderName[50],UIfilename[50];
	smpFio::ignorein(fin, ':', sSchoolFileName);
	smpFio::ignorein(fin, ':', sStudentFileName);
	smpFio::ignorein(fin, ':', UIfilename);
	smpFio::ignorein(fin, ':', sBackupFolderName);
	fin.close();

	smpFile::BackupFile(sSchoolFileName, sBackupFolderName);
	smpFile::BackupFile(sStudentFileName, sBackupFolderName);

	School school(sSchoolFileName, sStudentFileName);

	SchoolUI ui(school, UIfilename);

	ui.MainBranch();

	return 0;
}