
#include "../inc/push_swap.h"

#define MAX(X, Y) ((X > Y) ? X : Y)
#define MIN(X, Y) ((X < Y) ? X : Y)

#include "stdio.h"

int *longest_sub_seq(t_list *a) {

    int _max[2] = {0, 1};
    int *dp[3];
    int *nums;
    int size;

    size = ft_lstsize(a);
    nums = (int *)malloc(sizeof(int) * size);
    dp[0] = (int *)malloc(sizeof(int) * size);
    dp[1] = (int *)malloc(sizeof(int) * size);
    dp[2] = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        dp[0][i] = 1, dp[1][i] = dp[2][i] = 0, nums[i] = a->val, a = a->next;
    
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i] && dp[0][j] + 1 > dp[0][i])
                dp[0][i] = dp[0][j] + 1,
                dp[1][i] = j;
        if (_max[0] < dp[0][i])
            _max[0] = dp[0][i], _max[1] = i;
    }
    while (_max[0]--)
        dp[2][nums[_max[1]]] = 1, _max[1] = dp[1][_max[1]];
    return (free(dp[0]), free(dp[1]), free(nums), dp[2]);
}

void    a_to_b(t_list **a, t_list **b, int *sub) {
    
    int size = ft_lstsize(*a);
    int tmp = size;
    int flag = 1, f = size > 200, valid;

    for (int i = 0; i < size; i++)
    {
        if (i + 1 < size && (*a)->val > (*a)->next->val && (sub[(*a)->val] || sub[(*a)->next->val]))
        {
            valid = 1;
            for (int i = (*a)->next->val + 1; i < (*a)->val; i++)
                valid *= !sub[i];
            if (valid)
                sub[(*a)->val] = sub[(*a)->next->val] = 1,
                s(a, NULL, 'a');
        }
        if (sub[(*a)->val])
            ft_rotate(a),
            write(1, "ra\n", 3);
        else if ((*a)->val < tmp / 2 || !f || !flag)
        {
	        p(a, b, 'b');
            if ((flag && (*b)->next && (*b)->val > tmp / (2 + 2 * f))
                || (!flag && (*b)->next && (*b)->val > (tmp * 3) / 4))
                aff_r(b, 'b', 'b');
        }
        else
            ft_rotate(a),
            write(1, "ra\n", 3);
        if (flag && f && i + 1 == size)
            flag = 0, i = -1, size = ft_lstsize(*a);
    }
}

_instr _pos(t_list *a, int val)
{
    int size = ft_lstsize(a);
    int max = INT_MAX, min = INT_MAX;
    _instr _i, _a, _aa;

    _i.r = 0;
    _i.rr = size * (size > 1);
    while (size--)
    {
        if (a->val > val && a->val < max)
            max = a->val, _a = _i;
        if (a->val < min)
            min = a->val, _aa = _i;
        _i.r++;
        _i.rr--;
        a = a->next;
    }
    if (max == INT_MAX)
        return _aa;
    return _a;
}

int comb(_instr _a, _instr _b, int min)
{
    int a = MAX(_a.r, _b.r);
    int b = MAX(_a.rr, _b.rr);
    int c = _a.r + _b.rr;
    int d = _a.rr + _b.r;

    if (a <= b && a <= c && a <= d && a < min)
        return a;
    if (b <= a && b <= c && b <= d && b < min)
        return b;
    if (c <= b && c <= a && c <= d && c < min)
        return c;
    if (d <= b && d <= c && d <= a && d < min)
        return d;
    return min;
}

void    do_inst(t_list **as, t_list **bs, _instr _a, _instr _b)
{
    int a = MAX(_a.r, _b.r);
    int b = MAX(_a.rr, _b.rr);
    int c = _a.r + _b.rr;
    int d = _a.rr + _b.r;

    if (a <= b && a <= c && a <= d)
    {
        for (int i = _a.r; i > 0; i--)
            ft_rotate(as);
        for (int i = _b.r; i > 0; i--)
            ft_rotate(bs);
        for (int i = MIN(_a.r, _b.r); i; i--)
            write(1, "rr\n", 3), _a.r--, _b.r--;
        for (int i = _a.r; i > 0; i--)
            write(1, "ra\n", 3);
        for (int i = _b.r; i > 0; i--)
            write(1, "rb\n", 3);
    }
    else if (b <= a && b <= c && b <= d)
    {
        for (int i = _a.rr; i > 0; i--)
            ft_reverse_rotate(as);
        for (int i = _b.rr; i > 0; i--)
            ft_reverse_rotate(bs);
        for (int i = MIN(_a.rr, _b.rr); i; i--)
            write(1, "rrr\n", 4), _a.rr--, _b.rr--;
        for (int i = _a.rr; i; i--)
            write(1, "rra\n", 4);
        for (int i = _b.rr; i; i--)
            write(1, "rrb\n", 4);
    }
    else if (c <= b && c <= a && c <= d)
    {
        for (int i = _a.r; i > 0; i--)
            ft_rotate(as), write(1, "ra\n", 3);
        for (int i = _b.rr; i > 0; i--)
            ft_reverse_rotate(bs), write(1, "rrb\n", 4);
    }
    else
    {
        for (int i = _a.rr; i > 0; i--)
            ft_reverse_rotate(as), write(1, "rra\n", 4);
        for (int i = _b.r; i > 0; i--)
            ft_rotate(bs), write(1, "rb\n", 3);
    }
    p(as, bs, 'a');
}

void    b_to_a(t_list **a, t_list **b) {
    int min = INT_MAX;
    _instr _a, _b, _i, _j;
    int size = ft_lstsize(*b);
    t_list *tmp = *b;

    _i.r = 0;
    _i.rr = size * (size > 1);
    for (int i = 0; i < size; i++)
    {
        _j = _pos(*a, tmp->val);
        if (comb(_j, _i, min) < min)
            min = comb(_j, _i, min), _a = _j, _b = _i;
        _i.r++;
        _i.rr--;
        tmp = tmp->next;
    }
    do_inst(a, b, _a, _b);
}

void    sort_stack(t_list **a, t_list **b) {

    int *long_sub_seq = NULL, *tmp, max = 0;
    int size = ft_lstsize(*a);
    int sz = size;
    int count;

    while (size--)
    {
        count = 0;
        tmp = longest_sub_seq(*a);
        for (int i = 0; i < sz; i++)
            count += tmp[i];
        if (count > max)
            max = count, free(long_sub_seq), long_sub_seq = tmp;
        ft_rotate(a);
    }
    a_to_b(a, b, long_sub_seq);
    // for (int i = 0; i < 100; i++)
    //     if (long_sub_seq[i])
    //         printf("%d ", i);
    //         printf("\n");
    // while (aa)
    //     printf("%d ", aa->val), aa = aa->next;
    (void)b;
    // printf("\n");
    // aa = *b;
    // while (aa)
    //     printf("%d ", aa->val), aa = aa->next;
    while (*b)
        b_to_a(a, b);
        // b_to_a(a, b);
        // b_to_a(a, b);
        // b_to_a(a, b);
        // b_to_a(a, b);
        // b_to_a(a, b);
        // b_to_a(a, b);
        // b_to_a(a, b);
        // b_to_a(a, b);
        // b_to_a(a, b);
    move_to_top(a, 0, 'a');
    // t_list *aa = *a;
    // aa = *a;
    // while (aa)
    //     printf("%d ", aa->val), aa = aa->next;
}