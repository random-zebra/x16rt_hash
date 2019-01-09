import x16rt_hash
from binascii import hexlify, unhexlify

# Block 5000 (ce9e64ee2f9832f9ff6a8b042d0aa66f2e0aca6e8a5958051c141f27b5e68a3b)
blockheader_str = '0000002049963e9e46701e28e2dd44f61dea241ba3a457979fa3b378822c6cc24457bc2500a0da644814e2a43cc163f3f37590982e1e2f5ac45d1de2f8222750fea1c844f8d2315c824d111b120979e30000'

blockheader = unhexlify(blockheader_str)
powHash = x16rt_hash.getPoWHash(blockheader)
result = hexlify(powHash)
print(result)

testoutput = b'40abc3e30ba0552a7910c0acd5b46a5f8dbf287e0108ee679d59070000000000'
assert result == testoutput

print('Test succeeded')
