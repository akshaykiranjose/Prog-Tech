def largest_concat(list_t):
    if not list_t:
        return ''
    max_num = max(list_t)
    list_t.remove(max_num)
    return ''.join((str(max_num), largest_concat(list_t)))

list_t = [1,6,8,4,7]
max_conc = largest_concat(list_t)
print(max_conc)