/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef OCEANBASE_SQL_ENGINE_EXPR_RESULT_TYPE_UTIL_
#define OCEANBASE_SQL_ENGINE_EXPR_RESULT_TYPE_UTIL_

#include "lib/timezone/ob_timezone_info.h"
#include "lib/container/ob_bit_set.h"
#include "common/object/ob_obj_type.h"
#include "common/expression/ob_expr_string_buf.h"
#include "sql/engine/expr/ob_expr_operator.h"
#include "sql/engine/expr/ob_expr_res_type_map.h"

namespace oceanbase {
namespace sql {

class ObArithResultTypeMap;
class ObExprResultTypeUtil {
public:
  /* The way mysql calculates expressions is: first calculate a target type by column type,
   * Then, in the comparison stage, the value is converted to the modified type,
   * and then the comparison is made.
   * So the get_relational_cmp_type function is needed to calculate the target type
   **/
  static int get_relational_cmp_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);

  static int get_relational_cmp_type(
      common::ObObjType& type, const common::ObObjType& type1, const common::ObObjType& type2);

  static int get_relational_equal_type(
      common::ObObjType& type, const common::ObObjType& type1, const common::ObObjType& type2);

  static int get_relational_result_type(
      common::ObObjType& type, const common::ObObjType& type1, const common::ObObjType& type2);

  static int get_merge_result_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);

  static int get_merge_result_type(
      common::ObObjType& type, const common::ObObjType& type1, const common::ObObjType& type2);

  static int get_abs_result_type(common::ObObjType& type, const common::ObObjType& type1);

  static int get_neg_result_type(common::ObObjType& type, const common::ObObjType& type1);

  static int get_round_result_type(common::ObObjType& type, const common::ObObjType& type1);
  static int get_nanvl_result_type(
      common::ObObjType& type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_div_result_type(common::ObObjType& result_type, common::ObObjType& result_ob1_type,
      common::ObObjType& result_ob2_type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_div_result_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);

  static int get_int_div_result_type(common::ObObjType& result_type, common::ObObjType& result_ob1_type,
      common::ObObjType& result_ob2_type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_int_div_result_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);

  static int get_int_div_calc_type(common::ObObjType& calc_type, common::ObObjType& calc_ob1_type,
      common::ObObjType& calc_ob2_type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_mod_result_type(common::ObObjType& result_type, common::ObObjType& result_ob1_type,
      common::ObObjType& result_ob2_type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_mod_result_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);

  static int get_remainder_result_type(common::ObObjType& result_type, common::ObObjType& result_ob1_type,
      common::ObObjType& result_ob2_type, const common::ObObjType type1, const common::ObObjType type2);
  static int get_remainder_result_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);
  static int get_remainder_calc_type(common::ObObjType& calc_type, common::ObObjType& calc_ob1_type,
      common::ObObjType& calc_ob2_type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_arith_result_type(common::ObObjType& result_type, common::ObObjType& result_ob1_type,
      common::ObObjType& result_ob2_type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_arith_result_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);

  static int get_mul_result_type(common::ObObjType& result_type, common::ObObjType& result_ob1_type,
      common::ObObjType& result_ob2_type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_mul_result_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);

  static int get_add_result_type(common::ObObjType& result_type, common::ObObjType& result_ob1_type,
      common::ObObjType& result_ob2_type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_minus_result_type(common::ObObjType& result_type, common::ObObjType& result_ob1_type,
      common::ObObjType& result_ob2_type, const common::ObObjType type1, const common::ObObjType type2);

  static int get_add_result_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);

  static int get_minus_result_type(
      ObExprResType& res_type, const ObExprResType& res_type1, const ObExprResType& res_type2);

  static int get_sum_result_type(common::ObObjType& type, const common::ObObjType& type1);

  static int get_arith_calc_type(common::ObObjType& calc_type, common::ObObjType& calc_ob1_type,
      common::ObObjType& calc_ob2_type, const common::ObObjType type1, const common::ObObjType type2,
      const ObArithResultTypeMap::OP oper);
  static int deduce_max_string_length_oracle(const sql::ObSQLSessionInfo& session, const ObExprResType& orig_type,
      const common::ObLengthSemantics target_ls, common::ObLength& length);
  OB_INLINE static int get_add_calc_type(common::ObObjType& calc_type, common::ObObjType& calc_ob1_type,
      common::ObObjType& calc_ob2_type, const common::ObObjType type1, const common::ObObjType type2)
  {
    return get_arith_calc_type(calc_type, calc_ob1_type, calc_ob2_type, type1, type2, ObArithResultTypeMap::OP::ADD);
  }
  OB_INLINE static int get_minus_calc_type(common::ObObjType& calc_type, common::ObObjType& calc_ob1_type,
      common::ObObjType& calc_ob2_type, const common::ObObjType type1, const common::ObObjType type2)
  {
    return get_arith_calc_type(calc_type, calc_ob1_type, calc_ob2_type, type1, type2, ObArithResultTypeMap::OP::SUB);
  }
  OB_INLINE static int get_mul_calc_type(common::ObObjType& calc_type, common::ObObjType& calc_ob1_type,
      common::ObObjType& calc_ob2_type, const common::ObObjType type1, const common::ObObjType type2)
  {
    return get_arith_calc_type(calc_type, calc_ob1_type, calc_ob2_type, type1, type2, ObArithResultTypeMap::OP::MUL);
  }
  OB_INLINE static int get_div_calc_type(common::ObObjType& calc_type, common::ObObjType& calc_ob1_type,
      common::ObObjType& calc_ob2_type, const common::ObObjType type1, const common::ObObjType type2)
  {
    return share::is_oracle_mode()
               ? get_arith_calc_type(
                     calc_type, calc_ob1_type, calc_ob2_type, type1, type2, ObArithResultTypeMap::OP::DIV)
               : get_div_result_type(calc_type, calc_ob1_type, calc_ob2_type, type1, type2);
  }
  OB_INLINE static int get_mod_calc_type(common::ObObjType& calc_type, common::ObObjType& calc_ob1_type,
      common::ObObjType& calc_ob2_type, const common::ObObjType type1, const common::ObObjType type2)
  {
    return get_arith_calc_type(calc_type, calc_ob1_type, calc_ob2_type, type1, type2, ObArithResultTypeMap::OP::MOD);
  }
};

}  // namespace sql
}  // namespace oceanbase
#endif /* OCEANBASE_SQL_ENGINE_EXPR_RESULT_TYPE_UTIL_ */
