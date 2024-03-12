#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "../TList/TList.h"
//#include "../TList/THeadList.h"
#include "gtest.h"

TEST(TList, can_create_bitfield_with_positive_length)
{
  ASSERT_NO_THROW(TList<int> ());
}

TEST(TList, can_create_copy_and_right_getcurrent)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    ASSERT_NO_THROW(TList<int> l(list));

    TList <int> l(list);
    l.Reset();
    EXPECT_EQ(l.getCurrent(), 3);
    
}
TEST(TList, can_right_delete_and_dellist)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    ASSERT_NO_THROW(list.~TList());
    ASSERT_ANY_THROW(list.DelFirst());
}
TEST(TList, can_add_elements_after_delete)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    ASSERT_NO_THROW(list.~TList());
    ASSERT_ANY_THROW(list.DelFirst());
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.Reset();
    EXPECT_EQ(list.getCurrent(), 1);
}
TEST(TList, can_right_insfirst)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsFirst(4);
    list.Reset();
    EXPECT_EQ(list.getCurrent(), 4);
}
TEST(TList, can_right_inslast_and_setpos)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.SetPos(3);
    EXPECT_EQ(list.getCurrent(), 4);
}
TEST(TList, can_right_inscurr)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.SetPos(3);
    list.InsCurr(5);
    list.SetPos(3);
    EXPECT_EQ(list.getCurrent(), 5);
}
TEST(TList, can_right_delfirst)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.DelFirst();
    list.SetPos(0);
    EXPECT_EQ(list.getCurrent(), 2);
}
TEST(TList, can_right_delcurr)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.SetPos(1);

    list.DelCurr();
    list.SetPos(1);
    EXPECT_EQ(list.getCurrent(), 1);
}
TEST(TList, can_right_reset)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.Reset();
    EXPECT_EQ(list.getCurrent(), 3);
}
TEST(TList, can_right_gonext)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.Reset();
    list.GoNext();
    EXPECT_EQ(list.getCurrent(), 2);
}
TEST(TList, can_right_isend)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    list.InsLast(4);
    list.Reset();
    list.GoNext();
    EXPECT_EQ(list.IsEnd(), false);
}
TEST(TList, can_right_isend_true)
{
    TList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    
    list.Reset();
    list.GoNext();
    list.GoNext();
    list.GoNext();
    EXPECT_EQ(list.IsEnd(), true);
}
TEST(TList, throw_when_delcurr_from_empty_list)
{
    TList<int> list;
    ASSERT_ANY_THROW(list.DelCurr());
}
TEST(TList, throw_when_delfirst_from_empty_list)
{
    TList<int> list;
    ASSERT_ANY_THROW(list.DelFirst());
}
TEST(TList, throw_when_gonext_from_empty_list)
{
    TList<int> list;
    ASSERT_ANY_THROW(list.GoNext());
}
TEST(TList, throw_when_inscurr_from_empty_list)
{
    TList<int> list;
    ASSERT_ANY_THROW(list.InsCurr(1));
}
/*TEST(THeadList, can_create_headlist_with_positive_length)
{
    ASSERT_NO_THROW(THeadList<int>());
}

TEST(THeadList, can_create_copy_and_right_getcurrent)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    ASSERT_NO_THROW(THeadList<int> l(list));

    THeadList <int> l(list);
    l.Reset();
    EXPECT_EQ(l.getCurrent(), 3);

}
TEST(THeadList, can_right_delete_and_dellist)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    ASSERT_NO_THROW(list.~THeadList());
    ASSERT_ANY_THROW(list.DelFirst());
}
TEST(THeadList, can_add_elements_after_delete)
{
    THeadList<int> list;
    list.InsFirst(3);
    list.InsLast(2);
    list.InsLast(1);
    ASSERT_NO_THROW(list.~THeadList());
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
