/*
 Navicat Premium Data Transfer

 Source Server         : 本地MySQL数据库
 Source Server Type    : MySQL
 Source Server Version : 80016
 Source Host           : localhost:3306
 Source Schema         : test_hj212_db

 Target Server Type    : MySQL
 Target Server Version : 80016
 File Encoding         : 65001

 Date: 22/04/2021 21:15:56
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for monitordata
-- ----------------------------
DROP TABLE IF EXISTS `monitordata`;
CREATE TABLE `monitordata`  (
  `mn` varchar(255) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '站点编码',
  `datatime` datetime(0) NOT NULL COMMENT '数据时间',
  `paramCode` varchar(255) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '监测因子编码',
  `val` double(255, 0) NULL DEFAULT NULL COMMENT '监测数值',
  `mark` varchar(255) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '监测数据标记',
  PRIMARY KEY (`mn`, `datatime`, `paramCode`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_croatian_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of monitordata
-- ----------------------------
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a01001', -1, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a01002', 22, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a01006', 1032, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a01007', 4, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a01008', 353, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a05002', 34, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a05024', 6, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a21002', 18, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a21003', 5, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a21004', 9, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a21005', 1, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a21026', 2, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a24088', 35, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a34002', 124, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a34004', 25, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a34006', 874, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a34007', 2679, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a34049', 3553, 'N');
INSERT INTO `monitordata` VALUES ('LB4200001', '2021-01-07 14:38:00', 'a99999', 69, 'N');

-- ----------------------------
-- Table structure for station
-- ----------------------------
DROP TABLE IF EXISTS `station`;
CREATE TABLE `station`  (
  `mn` varchar(255) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '站点编码',
  `stationname` varchar(255) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '站点名称'
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_croatian_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
