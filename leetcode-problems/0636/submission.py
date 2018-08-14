class Solution:
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        level = 0
        stack = []
        pre_time = 0
        pre_id = -1
        mylist = [0] * n
        for strx in logs:
            item = strx.split(':')
            if item[1] == "start":
                level = level + 1
                if pre_id >= 0:
                    mylist[pre_id] = mylist[pre_id] + int(item[2])  - pre_time
                    #print("start ", item[2], pre_time)
                
                
                stack.append(pre_id)
                pre_id = int(item[0])
                pre_time = int(item[2])
                
            elif item[1] == "end":
                assert int(item[0]) == pre_id
                mylist[pre_id] = mylist[pre_id] + int(item[2]) - pre_time + 1
                
                #print("end ", item[2], pre_time)
                level = level - 1
                pre_id = stack.pop()
                pre_time = int(item[2]) + 1
                
                
        return mylist
