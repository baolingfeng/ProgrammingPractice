#!/usr/bin/env 
# -*- utf8 -*-
import os

def split_file(filename, split_num):
    """
    split file with a constant line number
    """
    root, ext = os.path.splitext(filename)
    with open(filename) as f:
        lines = f.readlines()
        total_line = len(lines)

        print lines[0].split('\t')

        size = total_line / split_num

        print 'Total line: %d, splited file line number: %d' % (total_line, size)

        total_line - size * split_num
        for i in range(0, split_num):
            split_file = root + '_' + str(i+1) + ext

            start = i * size;
            end = (i+1) * size;
            if i == split_num - 1:
                end = total_line

            print 'splite file %s: line from %d to %d' % (split_file, start, end)

            with open(split_file, 'w') as fw:
                for j in range(start, end):
                    fw.write('%s' % lines[j])

if __name__ == '__main__':
    filename = 'd:/tbl_interactions.csv'

    split_file(filename, 4)


