#include"IceUI.h"

//index 0角色 1起始 2至(n-4)中间 n-3结束 n-2延迟 n-1最大延迟
const char* IceUI::IcetoStr(smpAstr& smp, Ice& ice) {
	int* index = ice.index;
	int cantime = arrStartSkill[index[1]].canTime;
	int charatime = arrStartSkill[index[1]].isForward ? arrCharater[index[0]].forward : arrCharater[index[0]].reverse;

	//smp.add(arrCharater[index[0]].characterName).add(" ");

	smp + arrStartSkill[index[1]].nameStartSkill + ':';
	if (charatime)
		smp + (cantime + charatime) ;
	else
		smp + cantime ;

	smp + "  【";
	//smp + "→";
	for (int i = 2; i < ice.num - 3; i++)
		smp + (arrMidSkill[index[i]].nameMidSkill) + " ";
	smp + arrEndSkill[index[ice.num - 3]].nameEndSkill;
	//smp +"←";
	smp +"】";


	//if (index[ice.num - 2] != index[ice.num - 1]) {
	//	//smp + " [" + index[ice.num - 2] + "f," + index[ice.num - 1] + "f]";
	//	smp + "[" + (cantime - index[ice.num - 2]) + "f," + (cantime - index[ice.num - 1]) + "f] ";
	//	if (charatime)
	//		smp + "[" + (cantime - index[ice.num - 2] + charatime) + "f," + (cantime - index[ice.num - 1] + charatime) + "f]";
	//}
	//else {
	//	//smp + " [" + index[ice.num - 2] + "f]";
	//	smp + "[" + (cantime - index[ice.num - 1]) + "f] ";
	//	if (charatime)
	//		smp + "[" + (cantime - index[ice.num - 1] + charatime) + "f]";
	//}

	smp + "= [" + index[ice.num - 2];
	if (index[ice.num - 2] != index[ice.num - 1])
		smp + ',' + index[ice.num - 1];
	smp + ']';



	return smp.getBuffer();
}