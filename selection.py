import time
#selection sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr
def measure_time(sort_function, data):
    start_time = time.time()
    sort_function(data.copy())  # Sort a copy of the data to avoid modifying the original
    end_time = time.time()
    return end_time - start_time

arr = [817,1741,1291,254,387,1197,1673,1692,447,1332,436,426,1281,1302,1738,829,303,1461,588,1027,1747,1800,693,1905,453,115,828,500,569,1003,1804,873,1949,77,964,884,1174,1266,1909,896,509,1880,1946,1223,526,1821,1762,326,1755,1807,691,513,715,82,1894,80,200,1362,123,467,382,1554,1137,416,321,1446,132,1119,1698,1117,872,334,298,78,1785,1779,315,914,1591,763,418,682,1026,1163,1721,525,1859,372,1022,1548,73,957,68,1840,1494,1751,1466,1386,1398,1604,1917,1074,1283,446,1899,580,232,323,802,1629,330,121,1752,1644,1617,307,1395,1518,1685,1363,335,184,1288,1590,134,1545,176,653,85,499,805,1157,734,1553,1667,1808,618,1179,108,1496,1209,1653,129,876,638,1328,582,257,670,1415,1059,800,1901,1041,166,142,1615,1757,185,1247,1637,71,887,84,1770,877,1471,109,1366,650,1689,1002,211,703,64,1456,900,1734,1995,603,910,854,1057,1276,1942,1970,925,699,359,663,1887,288,1559,87,1210,389,521,1541,935,621,879,1088,1654,195,1982,1668,1430,214,938,1863,1263,72,439,1106,1280,986,1458,380,1089,1380,189,819,396,1438,1043,496,1201,999,565,533,557,1277,1419,363,196,460,1397,841,1881,1583,981,594,571,1879,862,160,1095,284,470,634,909,394,857,1638,482,1892,1200,1037,1066,175,1878,1407,713,644,1739,1902,1483,1723,1135,1038,1029,809,1275,1854,714,74,66,386,581,1352,531,1109,968,1631,1472,488,1586,1388,455,701,824,474,1536,1309,541,1918,1214,1488,985,1646,1246,1726,978,272,138,1991,459,624,1570,425,310,1769,1955,136,1314,930,1480,1670,1937,1165,685,1404,441,1669,1239,655,768,230,1907,1596,1710,236,1144,1853,1220,483,548,556,1624,1801,1806,1573,1198,1489,124,1956,1874,1845,1206,472,956,1152,193,1292,1836,1296,719,901,114,1434,125,698,233,469,1913,838,810,140,955,1433,1507,1236,177,299,1253,589,1950,1173,187,168,705,1861,1215,300,732,2000,1146,1980,1045,1058,1392,1680,918,751,601,1184,637,869,1662,1557,647,688,1849,1969,797,1703,356,1803,1047,702,975,1181,1543,1718,340,839,648,537,1219,1619,1649,133,1346,1104,1490,258,1329,1390,1990,1155,69,1400,1130,512,550,753,1479,507,649,1435,1416,1121,1977,939,928,208,595,1671,1477,511,645,1218,1375,159,772,1341,1639,1470,143,989,1330,812,784,1308,578,744,683,243,686,1158,898,368,216,218,527,393,514,1337,1393,190,553,555,946,1417,980,1267,913,266,1866,923,848,213,1301,201,660,1213,1401,1607,1039,1194,362,722,1396,1305,724,1484,1448,67,758,1282,740,1514,1844,1294,932,1867,308,113,302,890,646,448,1437,1599,667,1842,757,259,104,1439,279,1207,547,1756,1290,1750,1063,95,1080,1073,1592,1931,353,1815,1451,575,759,424,510,301,1787,276,348,1798,1422,1636,1105,706,1221,265,1697,806,1473,1576,639,381,1348,818,1897,1100,179,344,161,788,982,942,1618,856,1947,1008,1733,761,1132,771,1876,444,1524,1465,487,1464,710,1793,1890,1627,973,1732,1677,823,400,558,1204,1014,1307,1183,423,1960,1455,83,1657,1044,1481,234,415,727,994,1978,563,919,1245,1767,998,808,1944,888,1736,1516,1409,477,1053,599,328,57,1690,1147,139,373,654,1231,1138,1900,1628,947,1264,194,1550,1383,1118,428,651,895,1569,434,692,953,659,966,1327,1361,1413,1431,600,1141,598,1238,495,1722,1664,1987,345,390,1521,844,280,225,1658,731,1297,1655,1818,273,296,1371,412,1530,696,417,341,1951,1954,974,1149,1432,961,1974,392,1054,570,1212,1665,247,1112,590,1243,1613,267,1790,1678,1565,831,1065,1817,962,1156,894,787,1131,1758,318,1262,867,662,773,1975,1154,762,858,545,263,1777,675,1759,1064,1783,1186,1269,1303,1935,206,677,1099,1973,131,376,1293,1142,776,630,1013,625,51,347,1517,1248,445,1406,697,849,1424,906,319,827,486,1542,1693,1725,183,1705,427,1171,786,1323,411,769,1442,1091,592,1326,102,1707,156,449,1528,503,1911,1055,676,765,845,1440,948,242,395,743,327,992,1642,611,476,1936,1511,90,546,167,70,619,1681,1706,1896,1228,365,1872,1857,103,250,674,1030,1316,770,1966,91,264,1187,248,1491,1272,990,99,1622,336,1336,1882,1411,433,905,614,1512,1460,561,1205,1893,1740,790,309,1772,212,1998,958,1538,1694,1180,1885,991,1148,539,840,493,409,295,826,945,610,1611,893,1426,1579,1914,899,1075,1925,1242,1539,262,1227,1809,450,385,1572,915,331,1233,1997,1661,577,141,1708,1085,1033,126,494,491,1094,1042,162,1745,505,1208,1259,1081,438,632,911,1838,1782,92,1525,1587,1444,285,735,1021,58,217,620,430,1868,1040,1761,889,604,1321,1107,188,413,352,1742,801,664,1537,1883,219,110,1084,1847,1083,623,1961,1373,63,1274,1712,1814,1298,1224,952,1686,1640,1776,198,832,1285,337,1948,549,1886,1560,640,366,564,1699,297,370,1816,118,1019,1191,748,403,237,1598,1927,922,1720,1556,465,881,528,76,1805,1612,680,1151,1052,1009,332,401,1503,169,1988,1552,1369,1414,1967,261,959,378,1126,313,1279,874,53]
sorted_arr = selection_sort(arr)
print("Sorted array:", sorted_arr)
selection_sort_time = measure_time(selection_sort, arr)
print(f"Time taken by Selection Sort: {selection_sort_time:.6f} seconds")