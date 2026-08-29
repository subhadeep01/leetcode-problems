class Solution(object):
    def isPalindromic(self, s):
        """
        :type s: str
        :rtype: bool
        """
        ascii_values = [ord(char) for char in s]
        str_ans = ""
        for i in range(len(ascii_values)):
            binary_str = "{:08b}".format(int(ascii_values[i]))
            print(binary_str)
            str_ans+=binary_str
        return str_ans == str_ans[::-1]
