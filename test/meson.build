testexe = executable('testexe', 'test.cpp',
            include_directories : [inc, catch_inc])

visualTestexe = executable('visualTestexe', 'visualTest.cpp',
            include_directories : [inc, catch_inc])

test('app test', testexe)
test('visual test', visualTestexe)
