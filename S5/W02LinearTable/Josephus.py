class LinkNode:
    def __init__(self, value):
        self.value = value
        self.next = None


def create_cycle(total):
    head = LinkNode(1)
    prev = head
    index = 2
    while total - 1 > 0:
        curr = LinkNode(index)
        prev.next = curr
        prev = curr
        index += 1
        total -= 1
    curr.next = head
    return head


def run(total, tag):
    assert total >= 0, 'total lt 0'
    assert tag >= 0, 'tag lt 0'
    node = create_cycle(total)
    prev = None
    start = 1
    index = start
    while node and node.next:
        if index == tag:
            print(node.value)
            if tag == start:
                prev = node.next
                node.next = None
                node = prev
            else:
                prev.next = node.next
                node.next = None
                node = prev.next
        else:
            prev = node
            node = node.next
            index += 1


run(5, 999999)
