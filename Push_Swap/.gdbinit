# used to print nodes of a linked list

define plist
  set var $n = $arg0
  while $n
    print *($n)
    set var $n = $n->next
  end
end

document plist
        p_generic_list LIST_HEAD_POINTER
        Print all the fields of the nodes in the linked list pointed to by LIST_HEAD_POINTER. Assumes there is a next field in the struct.
end

# function to print indented nodes of a linked list
define indentby
    printf "\n"
    set $i_$arg0 = $arg0
    while $i_$arg0 > 10
        set $i_$arg0 = $i_$arg0 - 1
        printf "%c", ' '
    end
end

define print_nodes
    set $temp_node = stack_a
    while $temp_node != 0
        print *$temp_node->content
        set $temp_node = $temp_node->next
    end
end
document print_nodes
Prints the nodes of the linked list.
end