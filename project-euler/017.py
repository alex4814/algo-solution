# To make sure what British usage means, 
# see https://english.stackexchange.com/questions/111765/how-to-write-out-numbers-in-compliance-with-british-usage

groups = [
    '', 'thousand', 'million', 'billion'
]
atomic = [
    '', 'one', 'two', 'three', 'four', 
    'five', 'six', 'seven', 'eight', 'nine', 
    'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 
    'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen'
]
composite = [
    '', '', 'twenty', 'thirty', 'forty', 
    'fifty', 'sixty', 'seventy', 'eighty', 'ninety'
]

def write_group(x, p, head=True):
    if x == 0:
        return ''
    n = '{:03d}'.format(x)
    d = [int(a) for a in n]
    spells = []
    if d[0]:
        spells.append(atomic[d[0]])
        spells.append('hundred')
    if (d[1] or d[2]) and (d[0] or not head):
        spells.append('and')
    if d[1] > 1:
        spells.append(composite[d[1]])
        spells.append(atomic[d[2]])
    else:
        spells.append(atomic[d[1]*10 + d[2]])
    spells.append(groups[p])
    return ''.join(spells)
    
def write_out(x):
    n_group = (len(str(x)) + 2) / 3
    spells = []
    for i in xrange(n_group):
        y = x % 1000
        s = write_group(y, i, i == n_group - 1)
        x /= 1000
        spells.append(s)
    return ''.join(reversed(spells))

nums = range(1, 1001)
spells = [write_out(x) for x in nums]
print sum(len(s) for s in spells)

