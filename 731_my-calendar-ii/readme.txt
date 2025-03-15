法1：线段树+懒标记
	懒标记add，在pushDown()时，加到左右子节点的val上
法2：差分数组
	定义map，key为日期，val为预定次数的差分数组
	遍历map，是按key小到大排序的，累加val，得到原始数组
