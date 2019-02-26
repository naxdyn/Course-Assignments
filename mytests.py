import unittest
import myfunctions

class TestMyFunc(unittest.TestCase):

    def setUp(self):
        pass

    def test_double1(self):
        self.assertEqual(myfunctions.double(1), 2)
		
    def test_double2(self):
        self.assertEqual(myfunctions.double(3), 6)
		
    def test_halve1(self):
        self.assertEqual(myfunctions.halve(0), 0)
		
    def test_halve2(self):
        self.assertEqual(myfunctions.halve(4), 2)

if __name__ == '__main__':
unittest.main()