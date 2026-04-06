
import redis

redis_client = redis.Redis(
    host="172.22.108.19",
    port=6379,
    password="123456",
    decode_responses=True
)
print(redis_client.ping())