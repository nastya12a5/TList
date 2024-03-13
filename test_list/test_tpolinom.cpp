#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

//#include "../TList/TList.h"
//#include "../TList/THeadList.h"
#include "../TPolinom/TPolinom.h"
#include "gtest.h"
TEST(TPolinom, can_create_polinom)
{
    int ms1[][2] = { {-2,643},{-1,543},{9,100} };
    int mn1 = sizeof(ms1) / (2 * sizeof(int));
    
    ASSERT_NO_THROW(TPolinom (ms1,mn1));
}

TEST(TPolinom, can_create_copy)
{
    int ms1[][2] = { {-2,643},{-1,543},{9,100} };
    int mn1 = sizeof(ms1) / (2 * sizeof(int));

    TPolinom p(ms1, mn1);
    
    ASSERT_NO_THROW(TPolinom p1(p));
    TPolinom p1(p);
    EXPECT_EQ(p1==p, true);

}
TEST(TPolinom, can_add_monom)
{
    int ms1[][2] = { {-2,643},{-1,543},{9,100} };
    int mn1 = sizeof(ms1) / (2 * sizeof(int));

    TPolinom p(ms1, mn1);
    TMonom m(4, 443);
    p.AddMonom(m);
    int ms2[][2] = { {-2,643},{-1,543},{4,443}, {9,100} };
    int mn2 = sizeof(ms2) / (2 * sizeof(int));
    

    
    TPolinom p2(ms2, mn2);
   
    EXPECT_EQ(p.operator==(p2), true);
}
TEST(TPolinom, can_add_op_plus)
{
    int ms1[][2] = { {-2,643},{-1,543},{9,100} };
    int mn1 = sizeof(ms1) / (2 * sizeof(int));

    TPolinom p(ms1, mn1);

    int ms2[][2] = { {-2,643},{-1,543},{4,443}, {9,100} };
    int mn2 = sizeof(ms2) / (2 * sizeof(int));



    TPolinom p2(ms2, mn2);
    TPolinom p3 = p + p2;
    int ms3[][2] = { {-4,643},{-2,543},{4,443}, {18,100} };
    int mn3 = sizeof(ms3) / (2 * sizeof(int));

    TPolinom p4(ms3, mn3);
    EXPECT_EQ(p3.operator==(p4), true);
}
TEST (TPolinom, can_operator_add)
{
    int ms1[][2] = { {-2,643},{-1,543},{9,100} };
    int mn1 = sizeof(ms1) / (2 * sizeof(int));

    TPolinom p(ms1, mn1);

    int ms2[][2] = { {-2,643},{-1,543},{4,443}, {9,100} };
    int mn2 = sizeof(ms2) / (2 * sizeof(int));



    TPolinom p2(ms2, mn2);
    p += p2;
    int ms3[][2] = { {-4,643},{-2,543},{4,443}, {18,100} };
    int mn3 = sizeof(ms3) / (2 * sizeof(int));

    TPolinom p4(ms3, mn3);
    EXPECT_EQ(p.operator==(p4), true);
}
TEST(TPolinom, can_op_minus)
{
    int ms1[][2] = { {-2,643},{-1,543},{9,100} };
    int mn1 = sizeof(ms1) / (2 * sizeof(int));

    TPolinom p(ms1, mn1);

    int ms2[][2] = { {-2,643},{-1,543},{4,443}, {9,100} };
    int mn2 = sizeof(ms2) / (2 * sizeof(int));



    TPolinom p2(ms2, mn2);
    TPolinom p3=p2 - p;
    int ms3[][2] = { {4,443} };
    int mn3 = sizeof(ms3) / (2 * sizeof(int));

    TPolinom p4(ms3, mn3);
    EXPECT_EQ(p3.operator==(p4), true);
}
TEST(TPolinom, can_minus)
{
    int ms1[][2] = { {-2,643},{-1,543},{9,100} };
    int mn1 = sizeof(ms1) / (2 * sizeof(int));

    TPolinom p(ms1, mn1);

    int ms2[][2] = { {-2,643},{-1,543},{4,443}, {9,100} };
    int mn2 = sizeof(ms2) / (2 * sizeof(int));



    TPolinom p2(ms2, mn2);
      p -= p2;
    int ms3[][2] = { {-4,443} };
    int mn3 = sizeof(ms3) / (2 * sizeof(int));

    TPolinom p4(ms3, mn3);
    EXPECT_EQ(p.operator==(p4), true);
}
/*TEST(THeadList, can_add_elements_after_delete)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    ASSERT_NO_THROW(list.DelList());
    ASSERT_ANY_THROW(list.DelFirst());
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.Reset();
    EXPECT_EQ(list.getCurrent(), 1);
}
TEST(THeadList, can_right_insfirst)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsFirst(4);
    list.Reset();
    EXPECT_EQ(list.getCurrent(), 4);
}
TEST(THeadList, can_right_inslast_and_setpos)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.SetPos(3);
    EXPECT_EQ(list.getCurrent(), 4);
}
TEST(THeadList, can_right_inscurr)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.SetPos(3);
    list.InsCurr(5);
    list.SetPos(3);
    EXPECT_EQ(list.getCurrent(), 5);
}
TEST(THeadList, can_right_delfirst)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.DelFirst();
    list.SetPos(0);
    EXPECT_EQ(list.getCurrent(), 2);
}
TEST(THeadList, can_right_delcurr)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.SetPos(1);

    list.DelCurr();
    list.SetPos(1);
    EXPECT_EQ(list.getCurrent(), 1);
}
TEST(THeadList, can_right_reset)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.Reset();
    EXPECT_EQ(list.getCurrent(), 3);
}
TEST(THeadList, can_right_gonext)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.Reset();
    list.GoNext();
    EXPECT_EQ(list.getCurrent(), 2);
}
TEST(THeadList, can_right_isend)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.Reset();
    list.GoNext();
    EXPECT_EQ(list.IsEnd(), false);
}
TEST(THeadList, can_right_isend_true)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);

    list.Reset();
    list.GoNext();
    list.GoNext();
    list.GoNext();
    EXPECT_EQ(list.IsEnd(), true);
}
TEST(THeadList, throw_when_delcurr_from_empty_list)
{
    THeadList<int> list;
    ASSERT_ANY_THROW(list.DelCurr());
}
TEST(THeadList, throw_when_delfirst_from_empty_list)
{
    THeadList<int> list;
    ASSERT_ANY_THROW(list.DelFirst());
}
TEST(THeadList, throw_when_gonext_from_empty_list)
{
    THeadList<int> list;
    ASSERT_ANY_THROW(list.GoNext());
}
TEST(THeadList, throw_when_inscurr_from_empty_list)
{
    THeadList<int> list;
    ASSERT_ANY_THROW(list.InsCurr(1));
}*/